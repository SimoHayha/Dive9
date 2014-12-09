#include "stdafx.h"
#include "EvtInfoMessage.h"

using namespace Dive9;

EvtInfoMessage::EvtInfoMessage(std::wstring& message)
{
	m_message = message;
}

EvtInfoMessage::EvtInfoMessage(wchar_t const* message)
{
	m_message = std::wstring(message);
}

EvtInfoMessage::~EvtInfoMessage()
{
}

std::wstring EvtInfoMessage::GetEventName()
{
	return std::wstring(L"info_message");
}

eEvent EvtInfoMessage::GetEventType()
{
	return (INFO_MESSAGE);
}

std::wstring& EvtInfoMessage::GetinfoMessage()
{
	return m_message;
}