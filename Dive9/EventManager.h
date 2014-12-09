#pragma once

#include "stdafx.h"
#include "IEvent.h"
#include "IEventListener.h"

namespace Dive9
{
	class EventManager
	{
	public:
		EventManager();
		virtual ~EventManager();

		bool	AddEventListener(eEvent eventID, IEventListener* listener);
		bool	DelEventListener(eEvent eventID, IEventListener* listener);

		bool	ProcessEvent(EventPtr event);
		bool	QueueEvent(EventPtr event);
		bool	ProcessEventQueue();

		static EventManager*	Get();

	protected:
		std::vector<IEventListener*>	m_eventHandlers[NUM_EVENTS];
		std::vector<EventPtr>			m_eventQueue;

		static EventManager*	ms_eventManager;
	};
}