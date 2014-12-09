#include "stdafx.h"
#include "EvtErrorMessage.h"

using namespace Dive9;

EvtErrorMessage::EvtErrorMessage(std::wstring& message)
{
	m_message = message;
}

EvtErrorMessage::EvtErrorMessage(wchar_t const* message)
{
	m_message = std::wstring(message);
}

EvtErrorMessage::~EvtErrorMessage()
{
}

std::wstring EvtErrorMessage::GetEventName()
{
	return std::wstring(L"info_message");
}

eEvent EvtErrorMessage::GetEventType()
{
	return ERROR_MESSAGE;
}

std::wstring& EvtErrorMessage::GetErrorMessage()
{
	return m_message;
}