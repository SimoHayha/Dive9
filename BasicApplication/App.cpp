#include "App.h"

App	AppInstance;

App::App()
{
}

App::~App()
{
}

bool App::ConfigureEngineComponent()
{
	int		width = 640;
	int		height = 320;
	bool	windowed = true;

	m_window = new Win32RenderWindow();
	m_window->Initialize(this);

	return true;
}

void App::ShutdownEngineComponent()
{
	if (m_window)
	{
		m_window->Shutdown();
		delete m_window;
	}
}

void App::Initialize()
{
}

void App::Update()
{
}

void App::Shutdown()
{
}

std::wstring App::GetName()
{
	return L"BasicApplication";
}

