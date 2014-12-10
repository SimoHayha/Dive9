#pragma once

#include "Application.h"

#include "Win32RenderWindow.h"
#include "GLRenderWindow.h"

using namespace Dive9;

class App : public Application
{
public:
	App();
	virtual ~App();

	virtual void	ConfigureCommandLine(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lPcmdline, int ncmdshow) override;
	virtual bool	ConfigureEngineComponent() override;
	virtual void	ShutdownEngineComponent() override;
	virtual void	Initialize() override;
	virtual void	Update() override;
	virtual void	Shutdown() override;

	virtual bool	HandleEvent(EventPtr event) override;

	virtual std::wstring	GetName() override;

protected:
	Win32RenderWindow*	m_window;
	GLRenderWindow*		m_glfwWindow;

	HINSTANCE	m_hInst; 
	HINSTANCE	m_hPrevInst; 
	LPSTR		m_lPcmdline;
	int			m_ncmdshow;
};