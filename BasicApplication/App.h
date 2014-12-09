#pragma once

#include "Application.h"

#include "Win32RenderWindow.h"

using namespace Dive9;

class App : public Application
{
public:
	App();
	virtual ~App();

	virtual bool ConfigureEngineComponent() override;
	virtual void ShutdownEngineComponent() override;
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Shutdown() override;

	virtual std::wstring	GetName() override;

protected:
	Win32RenderWindow*	m_window;
};