#pragma once

#include "stdafx.h"

namespace Dive9
{
	class IWindowProc
	{
	public:
		virtual LRESULT	WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
		virtual void	BeforeRegisterWindowClass(WNDCLASSEX& wc) = 0;
	};
}