#pragma once

#include "stdafx.h"
#include "EvtKeyboardMsg.h"

namespace Dive9
{
	class EvtKeyUp : public EvtKeyboardMsg
	{
	public:
		EvtKeyUp(HWND hWnd, unsigned int wParam, long lParam);
		virtual ~EvtKeyUp();

		virtual std::wstring	GetEventName() override;
		virtual eEvent			GetEventType() override;
	};

	typedef std::shared_ptr<EvtKeyUp>	EvtKeyUpPtr;
}