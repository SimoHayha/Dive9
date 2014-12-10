#include "stdafx.h"
#include "IWindowProc.h"
#include "Win32RenderWindow.h"

using namespace Dive9;

extern LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

Win32RenderWindow::Win32RenderWindow()
{
	m_hWnd = nullptr;

	m_style = (WS_OVERLAPPEDWINDOW | WS_VISIBLE);
}

Win32RenderWindow::~Win32RenderWindow()
{
	Shutdown();
}

LRESULT CALLBACK InternalWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LONG_PTR	objPtr = GetWindowLongPtr(hWnd, 0);

	if (!objPtr)
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	else
		return ((IWindowProc*)objPtr)->WindowProc(hWnd, uMsg, wParam, lParam);
}

void Win32RenderWindow::Initialize(IWindowProc* windowProcObj)
{
	WNDCLASSEX	wc;

	memset(&wc, 0, sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = InternalWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = sizeof(windowProcObj);
	wc.hInstance = 0;
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = L"D3D Engine";
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	windowProcObj->BeforeRegisterWindowClass(wc);

	RegisterClassEx(&wc);

	RECT	rc;
	rc.top = 0;
	rc.left = 0;
	rc.right = m_width;
	rc.bottom = m_height;

	AdjustWindowRectEx(&rc, m_style, false, 0);

	long	width = rc.right - rc.left;
	long	height = rc.bottom - rc.top;

	long	left = (long)m_left;
	long	top = (long)m_top;

	m_hWnd = CreateWindowEx(
		0,
		wc.lpszClassName,
		L"DirectX 11",
		m_style,
		left,
		top,
		width,
		height,
		nullptr,
		nullptr,
		nullptr,
		nullptr
		);

	RECT	rect;
	GetClientRect(m_hWnd, &rect);
	m_width = rect.right - rect.left;
	m_height = rect.bottom - rect.top;

	if (m_hWnd)
	{
		LONG_PTR ret = SetWindowLongPtr(m_hWnd, 0, (LONG_PTR)windowProcObj);
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}
}

void Win32RenderWindow::Shutdown()
{
	if (m_hWnd)
		DestroyWindow(m_hWnd);
	m_hWnd = nullptr;
}

void Win32RenderWindow::Paint()
{
}