#include "stdafx.h"
#include "EvtInfoMessage.h"
#include "EvtErrorMessage.h"

#include "EvtKeyUp.h"

#include "EvtWindowCreate.h"

#include "Log.h"

#include "Application.h"

using namespace Dive9;

Application*	Application::ms_application = nullptr;

Application::Application()
{
	ms_application = this;

	Log::Get().Open();

	SetEventManager(&EvtManager);

	RequestEvent(SYSTEM_KEYBOARD_KEYUP);
	RequestEvent(SYSTEM_KEYBOARD_KEYDOWN);
	RequestEvent(SYSTEM_KEYBOARD_CHAR);
	RequestEvent(INFO_MESSAGE);
	RequestEvent(ERROR_MESSAGE);
}

Application::~Application()
{
	Log::Get().Close();
}

Application* Application::GetApplication()
{
	return ms_application;
}

void Application::RequestTermination()
{
	PostQuitMessage(0);
}

bool Application::HandleEvent(EventPtr event)
{
	eEvent	e = event->GetEventType();

	if (e == INFO_MESSAGE)
	{
		EvtInfoMessagePtr	infoMessage = std::static_pointer_cast<EvtInfoMessage>(event);
		MessageBox(nullptr, infoMessage->GetinfoMessage().c_str(), L"Engine :: Info message", MB_ICONINFORMATION | MB_SYSTEMMODAL);
	}
	else if (e == ERROR_MESSAGE)
	{
		EvtErrorMessagePtr	errorMessage = std::static_pointer_cast<EvtErrorMessage>(event);
		MessageBox(nullptr, errorMessage->GetErrorMessage().c_str(), L"Engine :: error message", MB_ICONERROR | MB_SYSTEMMODAL);
	}
	else if (e == SYSTEM_KEYBOARD_KEYUP)
	{
		EvtKeyUpPtr	keyUp = std::static_pointer_cast<EvtKeyUp>(event);

		unsigned int	key = keyUp->GetCharacterCode();

		if (key == VK_ESCAPE)
		{
			RequestTermination();
			return true;
		}
	}

	return false;
}

void Application::MessageLoop()
{
	MSG	msg;

	while (true)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				return;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);

		Update();
	}
}

void Application::BeforeRegisterWindowClass(WNDCLASSEX& wc)
{
	UNREFERENCED_PARAMETER(wc);
}

LRESULT Application::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		EvtWindowCreatePtr	event = EvtWindowCreatePtr(new EvtWindowCreate(hWnd, wParam, lParam));
		EvtManager.ProcessEvent(event);
	} break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	} break;
	case WM_KEYUP:
	{
		EvtKeyUpPtr	event = EvtKeyUpPtr(new EvtKeyUp(hWnd, wParam, lParam));
		EvtManager.ProcessEvent(event);
	} break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void Application::ConfigureCommandLine(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lPcmdline, int ncmdshow)
{
	UNREFERENCED_PARAMETER(hInst);
	UNREFERENCED_PARAMETER(hPrevInst);
	UNREFERENCED_PARAMETER(lPcmdline);
	UNREFERENCED_PARAMETER(ncmdshow);
}