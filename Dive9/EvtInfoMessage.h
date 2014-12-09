#pragma once

#include "stdafx.h"
#include "IEvent.h"

namespace Dive9
{
	class EvtInfoMessage : public IEvent
	{
	public:
		EvtInfoMessage(std::wstring& message);
		EvtInfoMessage(wchar_t const* message);
		virtual ~EvtInfoMessage();

		virtual std::wstring	GetEventName() override;
		virtual eEvent			GetEventType() override;

		std::wstring&	GetinfoMessage();

	protected:
		std::wstring	m_message;
	};

	typedef std::shared_ptr<EvtInfoMessage>	EvtInfoMessagePtr;
}