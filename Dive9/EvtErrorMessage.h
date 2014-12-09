#pragma once

#include "stdafx.h"
#include "IEvent.h"

namespace Dive9
{
	class EvtErrorMessage : public IEvent
	{
	public:
		EvtErrorMessage(std::wstring& message);
		EvtErrorMessage(wchar_t const* message);
		virtual ~EvtErrorMessage();

		virtual std::wstring	GetEventName() override;
		virtual eEvent			GetEventType() override;

		std::wstring&	GetErrorMessage();

	protected:
		std::wstring	m_message;
	};

	typedef std::shared_ptr<EvtErrorMessage>	EvtErrorMessagePtr;
}