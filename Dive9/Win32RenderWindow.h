#pragma once

#include "stdafx.h"
#include "RenderWindow.h"

namespace Dive9
{
	class IWindowProc;

	class Win32RenderWindow : public RenderWindow
	{
	public:
		Win32RenderWindow();
		virtual ~Win32RenderWindow();

		virtual void	Initialize(IWindowProc* windowProcObj) override;
		virtual void	Shutdown() override;
		virtual void	Paint() override;
	};
}