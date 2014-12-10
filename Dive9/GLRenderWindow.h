#pragma once

#include "stdafx.h"

#include <gl/GL.h>

#include "RenderWindow.h"

namespace Dive9
{
	class IWindowProc;

	class GLRenderWindow : public RenderWindow
	{
	public:
		GLRenderWindow(HINSTANCE hInstance);
		virtual ~GLRenderWindow();

		virtual void Initialize(IWindowProc* windowProcObj) override;
		virtual void Shutdown() override;
		virtual void Paint() override;

	protected:
		HINSTANCE	m_hInstance;
	};
}