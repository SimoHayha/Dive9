#include "stdafx.h"

#include "RenderWindow.h"

using namespace Dive9;

RenderWindow::RenderWindow()
{
	m_hWnd = nullptr;
	m_width = 640;
	m_height = 480;
	m_left = 100;
	m_top = 100;

	m_style = (WS_OVERLAPPEDWINDOW | WS_VISIBLE);
}

RenderWindow::~RenderWindow()
{
}

HWND RenderWindow::GetHandle() const
{
	return m_hWnd;
}

void RenderWindow::SetWidth(int width)
{
	m_width = width;

	UpdateWindowState();
}

void RenderWindow::SetHeight(int height)
{
	m_height = height;

	UpdateWindowState();
}

int RenderWindow::GetWidth() const
{
	RECT	rect;
	GetClientRect(m_hWnd, &rect);

	return (rect.right - rect.left);
}

int RenderWindow::GetHeight() const
{
	RECT	rect;
	GetClientRect(m_hWnd, &rect);

	return (rect.bottom - rect.top);
}

int RenderWindow::GetLeft() const
{
	POINT	point;
	point.x = 0;
	point.y = 0;

	ClientToScreen(m_hWnd, &point);

	return point.x;
}

int RenderWindow::GetTop() const
{
	POINT	point;
	point.x = 0;
	point.y = 0;

	ClientToScreen(m_hWnd, &point);

	return point.y;
}

void RenderWindow::UpdateWindowState()
{
	if (m_hWnd)
	{
		RECT	clientRect;
		clientRect.left = 0;
		clientRect.top = 0;
		clientRect.right = m_width;
		clientRect.bottom = m_height;

		RECT	windowRect = clientRect;
		AdjustWindowRect(&windowRect, m_style, false);

		int	deltaX = (windowRect.right - clientRect.right) / 2;
		int	deltaY = (windowRect.bottom - clientRect.bottom) / 2;

		MoveWindow(m_hWnd, m_left - deltaX, m_top - deltaY, m_width + deltaX * 2, m_height + deltaY * 2, true);
	}
}