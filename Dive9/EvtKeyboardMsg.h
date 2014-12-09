#pragma once

#include "stdafx.h"
#include "EvtWindowMsg.h"

namespace Dive9
{
	class EvtKeyboardMsg : public EvtWindowMsg
	{
	public:
		EvtKeyboardMsg(HWND hWnd, unsigned int wParam, long lParam);
		virtual ~EvtKeyboardMsg();

		unsigned int	GetCharacterCode() const;
		unsigned int	GetRepeatCount() const;
		unsigned int	GetScanCode() const;
		bool			GetExtendedKey() const;
		bool			GetContextCode() const;
		bool			GetPreviousKeyState() const;
		bool			GetTransitionState() const;
	};

	typedef std::shared_ptr<EvtKeyboardMsg>	EvtKeyboardMsgPtr;
}