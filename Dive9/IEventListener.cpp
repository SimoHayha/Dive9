#include "stdafx.h"
#include "EventManager.h"
#include "IEventListener.h"

using namespace Dive9;

IEventListener::IEventListener() :
m_eventManager(nullptr)
{
}

IEventListener::~IEventListener()
{
	SetEventManager(nullptr);
}

void IEventListener::RequestEvent(eEvent e)
{
	bool	alreadyRequested = false;

	for (auto requested : m_requestedEvents)
	{
		if (requested == e)
			alreadyRequested = true;
	}

	if (alreadyRequested)
	{
		
	}
	else
	{
		m_requestedEvents.push_back(e);

		if (m_eventManager)
			m_eventManager->AddEventListener(e, this);
	}
}

void IEventListener::UnRequestEvent(eEvent e)
{
	for (auto it = m_requestedEvents.begin(); it != m_requestedEvents.end(); ++it)
	{
		if ((*it) == e)
			it = m_requestedEvents.erase(it);
	}

	if (m_eventManager)
		m_eventManager->DelEventListener(e, this);
}

void IEventListener::SetEventManager(EventManager* eventManager)
{
	if (m_eventManager)
	{
		for (auto e : m_requestedEvents)
			m_eventManager->DelEventListener(e, this);
	}

	m_eventManager = eventManager;

	if (m_eventManager)
	{
		for (auto e : m_requestedEvents)
			m_eventManager->AddEventListener(e, this);
	}
}