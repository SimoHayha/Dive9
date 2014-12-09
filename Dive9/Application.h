#pragma once

#include "stdafx.h"
#include "EventManager.h"
#include "IEventListener.h"
#include "IWindowProc.h"

namespace Dive9
{
	class Application : public IEventListener, public IWindowProc
	{
	public:
		EventManager	EvtManager;

		Application();
		virtual ~Application();

		static Application*	GetApplication();

		virtual bool	ConfigureEngineComponent() = 0;
		virtual void	ShutdownEngineComponent() = 0;
		virtual void	Initialize() = 0;
		virtual void	Update() = 0;
		virtual void	Shutdown() = 0;
		virtual void	MessageLoop();
		virtual LRESULT	WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual void	BeforeRegisterWindowClass(WNDCLASSEX& wc);

		virtual bool	HandleEvent(EventPtr event);

		void			RequestTermination();

	protected:
		static Application*	ms_application;
	};
}