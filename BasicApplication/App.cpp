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

// Configure the render windows and renderer modes
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

// Initialize everything else (entity, scenes ...)
void App::Initialize()
{
}

// Update loop
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
	return Application::HandleEvent(event);
}

void App::ConfigureCommandLine(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lPcmdline, int ncmdshow)
{
	m_hInst = hInst;
	m_hPrevInst = hPrevInst;
	m_lPcmdline = lPcmdline;
	m_ncmdshow = ncmdshow;
}

