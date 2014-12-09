#include "stdafx.h"
#include "EvtKeyUp.h"

using namespace Dive9;

EvtKeyUp::EvtKeyUp(HWND hWnd, unsigned int wParam, long lParam) :
EvtKeyboardMsg(hWnd, wParam, lParam)
{
}

EvtKeyUp::~EvtKeyUp()
{
}

std::wstring EvtKeyUp::GetEventName()
{
	return std::wstring(L"keyboard_keyup");
}

eEvent EvtKeyUp::GetEventType()
{
	return SYSTEM_KEYBOARD_KEYUP;
}