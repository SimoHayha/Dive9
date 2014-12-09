#pragma once

#include "stdafx.h"

namespace Dive9
{
	class IWindowProc;

	class RenderWindow
	{
	public:
		RenderWindow();
		virtual ~RenderWindow();

		virtual void	Initialize(IWindowProc* windowProcObj) = 0;
		virtual void	Shutdown() = 0;
		virtual void	Paint() = 0;

		HWND	GetHandle() const;

		void	SetWidth(int width);
		void	SetHeight(int height);

		int	GetWidth() const;
		int	GetHeight() const;
		int	GetLeft() const;
		int	GetTop() const;

	protected:
		HWND	m_hWnd;
		int		m_width;
		int		m_height;
		int		m_left;
		int		m_top;

		DWORD	m_style;

		void	UpdateWindowState();
	};
}