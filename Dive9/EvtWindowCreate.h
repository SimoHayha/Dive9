#pragma once

#include "stdafx.h"
#include "EvtWindowMsg.h"

namespace Dive9
{
	class EvtWindowCreate : public EvtWindowMsg
	{
	public:
		EvtWindowCreate(HWND hWnd, unsigned int wParam, long lParam);
		virtual ~EvtWindowCreate();

		virtual std::wstring	GetEventName() override;
		virtual eEvent			GetEventType() override;
	};

	typedef std::shared_ptr<EvtWindowCreate>	EvtWindowCreatePtr;
}