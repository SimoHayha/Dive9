#include "stdafx.h"
#include "EvtWindowMsg.h"

using namespace Dive9;

EvtWindowMsg::EvtWindowMsg(HWND hWnd, unsigned int wParam, long lParam)
{
	m_hWnd = hWnd;
	m_wParam = wParam;
	m_lParam = lParam;
}

EvtWindowMsg::~EvtWindowMsg()
{
}

HWND EvtWindowMsg::GetWindowHandle() const
{
	return m_hWnd;
}

unsigned int EvtWindowMsg::GetWParam() const
{
	return m_wParam;
}

unsigned int EvtWindowMsg::GetLParam() const
{
	return m_lParam;
}