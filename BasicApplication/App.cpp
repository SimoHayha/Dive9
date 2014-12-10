#include "EvtWindowCreate.h"
#include "App.h"

App	AppInstance;

App::App()
{
	RequestEvent(SYSTEM_WINDOW_CREATE);
}

App::~App()
{
}

bool App::ConfigureEngineComponent()
{
	int		width = 640;
	int		height = 320;
	bool	windowed = true;

	m_window = new Win32RenderWindow();
	m_window->Initialize(this);

	m_glfwWindow = new GLRenderWindow(m_hInst);
	m_glfwWindow->Initialize(this);

	return true;
}

void App::ShutdownEngineComponent()
{
	if (m_window)
	{
		m_window->Shutdown();
		delete m_window;
	}

	if (m_glfwWindow)
	{
		m_glfwWindow->Shutdown();
		delete m_glfwWindow;
	}
}

void App::Initialize()
{
}

void App::Update()
{
}

void App::Shutdown()
{
}

std::wstring App::GetName()
{
	return L"BasicApplication";
}

bool App::HandleEvent(EventPtr event)
{
	if (event->GetEventType() == SYSTEM_WINDOW_CREATE)
	{
		EvtWindowCreatePtr	createMessage = std::static_pointer_cast<EvtWindowCreate>(event);
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

		HDC	ourWindowHandleToDeviceContext = GetDC(createMessage->GetWindowHandle());

		int	letWindowsChooseThisPixelFormat;
		letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
		SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

		HGLRC	ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
		wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

		MessageBoxA(nullptr, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);
	}

	return Application::HandleEvent(event);
}

void App::ConfigureCommandLine(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lPcmdline, int ncmdshow)
{
	m_hInst = hInst;
	m_hPrevInst = hPrevInst;
	m_lPcmdline = lPcmdline;
	m_ncmdshow = ncmdshow;
}

