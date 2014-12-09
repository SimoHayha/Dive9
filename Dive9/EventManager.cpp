#include "stdafx.h"
#include "EventManager.h"

using namespace Dive9;

EventManager*	EventManager::ms_eventManager = nullptr;

EventManager::EventManager()
{
	if (!ms_eventManager)
		ms_eventManager = this;
}

EventManager::~EventManager()
{
	for (unsigned int e = 0; e < NUM_EVENTS; e++)
	{
		for (unsigned int i = 0; i < m_eventHandlers[e].size(); i++)
		{
			m_eventHandlers[e][i]->SetEventManager(nullptr);
		}
	}
}

EventManager* EventManager::Get()
{
	return ms_eventManager;
}

bool EventManager::AddEventListener(eEvent eventID, IEventListener* listener)
{
	if (eventID >= NUM_EVENTS)
		return false;

	m_eventHandlers[eventID].push_back(listener);

	return true;
}

bool EventManager::DelEventListener(eEvent eventID, IEventListener* listener)
{
	if (eventID >= NUM_EVENTS)
		return false;

	bool	result = false;

	for (auto it = m_eventHandlers[eventID].begin(); it != m_eventHandlers[eventID].end(); ++it)
	{
		if ((*it) == listener)
		{
			m_eventHandlers[eventID].erase(it);
			result = true;
			break;
		}
	}

	return result;
}

bool EventManager::ProcessEvent(EventPtr event)
{
	if (!event)
		return false;

	eEvent			e = event->GetEventType();
	unsigned int	num = m_eventHandlers[e].size();

	bool	handled = false;

	for (unsigned int i = 0; i < num; i++)
	{
		handled = m_eventHandlers[e][i]->HandleEvent(event);
		if (handled)
			break;
	}

	return handled;
}

bool EventManager::QueueEvent(EventPtr event)
{
	return true;
}

bool EventManager::ProcessEventQueue()
{
	return true;
}