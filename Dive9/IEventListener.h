#pragma once

#include "stdafx.h"
#include "IEvent.h"

namespace Dive9
{
	class EventManager;

	class IEventListener
	{
	public:
		IEventListener();
		virtual ~IEventListener();

		virtual std::wstring	GetName() = 0;
		virtual bool			HandleEvent(EventPtr event) = 0;

		void	RequestEvent(eEvent e);
		void	UnRequestEvent(eEvent e);
		void	SetEventManager(EventManager* eventManager);

	private:
		EventManager*		m_eventManager;
		std::vector<eEvent>	m_requestedEvents;
	};
}