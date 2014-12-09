#pragma once

#include "stdafx.h"
#include "IEvent.h"

namespace Dive9
{
	class EvtWindowMsg : public IEvent
	{
	public:
		EvtWindowMsg(HWND hWnd, unsigned int wParam, long lParam);
		virtual ~EvtWindowMsg();

		HWND			GetWindowHandle() const;
		unsigned int	GetWParam() const;
		unsigned int	GetLParam() const;

	protected:
		HWND			m_hWnd;
		unsigned int	m_wParam;
		unsigned int	m_lParam;
	};

	typedef std::shared_ptr<EvtWindowMsg>	EvtWindowMsgPtr;
}