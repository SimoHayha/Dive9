#include "stdafx.h"
#include "EvtWindowCreate.h"

using namespace Dive9;

EvtWindowCreate::EvtWindowCreate(HWND hWnd, unsigned int wParam, long lParam) :
EvtWindowMsg(hWnd, wParam, lParam)
{
}

EvtWindowCreate::~EvtWindowCreate()
{
}

std::wstring Dive9::EvtWindowCreate::GetEventName()
{
	return std::wstring(L"wm_create");
}

Dive9::eEvent Dive9::EvtWindowCreate::GetEventType()
{
	return SYSTEM_WINDOW_CREATE;
}
