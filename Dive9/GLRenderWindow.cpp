#include "stdafx.h"
#include "IWindowProc.h"
#include "GLRenderWindow.h"

using namespace Dive9;

extern LRESULT CALLBACK InternalWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

GLRenderWindow::GLRenderWindow(HINSTANCE hInstance)
{
	m_hWnd = nullptr;

	m_style = (WS_OVERLAPPEDWINDOW | WS_VISIBLE);
}

GLRenderWindow::~GLRenderWindow()
{
	Shutdown();
}

void GLRenderWindow::Initialize(IWindowProc* windowProcObj)
{
	WNDCLASS	wc;

	memset(&wc, 0, sizeof(wc));
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = InternalWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = sizeof(windowProcObj);
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = L"GL Engine";
	//windowProcObj->BeforeRegisterWindowClass(wc);

	RegisterClass(&wc);

	RECT	rc;
	rc.top = 0;
	rc.left = 0;
	rc.right = m_width;
	rc.bottom = m_height;

	AdjustWindowRect(&rc, m_style, false);

	long	width = rc.right - rc.left;
	long	height = rc.bottom - rc.top;

	long	left = (long)m_left;
	long	top = (long)m_top;

	m_hWnd = CreateWindowW(
		wc.lpszClassName,
		L"OpenGL",
		m_style,
		left,
		top,
		width,
		height,
		nullptr,
		nullptr,
		m_hInstance,
		nullptr
		);

	RECT	rect;
	GetClientRect(m_hWnd, &rect);
	m_width = rect.right - rect.left;
	m_height = rect.bottom - rect.top;

	if (m_hWnd)
	{
		SetWindowLongPtr(m_hWnd, 0, (LONG_PTR)windowProcObj);
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}
}

void GLRenderWindow::Shutdown()
{
}

void GLRenderWindow::Paint()
{
}
