#include "stdafx.h"
#include "IWindowProc.h"
#include "GLRenderWindow.h"

using namespace Dive9;

extern LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//extern LRESULT CALLBACK InternalWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

GLRenderWindow::GLRenderWindow(HINSTANCE hInstance)
{
	m_hWnd = nullptr;

	m_style = (WS_OVERLAPPEDWINDOW | WS_VISIBLE);
}

GLRenderWindow::~GLRenderWindow()
{
	Shutdown();
}

void GLConfigure(HWND hWnd)
{
	PIXELFORMATDESCRIPTOR	pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,
		8,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	HDC	ourWindowHandleToDeviceContext = GetDC(hWnd);

	int	letWindowsChooseThisPixelFormat;
	letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
	SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

	HGLRC	ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
	wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

	MessageBoxA(nullptr, (char*)glGetString(GL_VERSION), "OPENGL VERSION (context ok)", 0);
}

LRESULT CALLBACK GLInternalWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LONG_PTR	objPtr = GetWindowLongPtr(hWnd, 0);

	if (uMsg == WM_CREATE)
		GLConfigure(hWnd);

	if (!objPtr)
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	else
		return ((IWindowProc*)objPtr)->WindowProc(hWnd, uMsg, wParam, lParam);
}

void GLRenderWindow::Initialize(IWindowProc* windowProcObj)
{
	WNDCLASS	wc;

	memset(&wc, 0, sizeof(wc));
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = GLInternalWindowProc;
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
		SetLastError(0);
		LONG_PTR ret = SetWindowLongPtr(m_hWnd, 0, (LONG_PTR)windowProcObj); // Not working with a simple WNDCLASS
		DWORD error = GetLastError();
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
