#pragma once

#include "stdafx.h"

namespace Dive9
{
	enum eEvent
	{
		RENDER_FRAME_START,
		SYSTEM_LBUTTON_DOWN,
		SYSTEM_LBUTTON_UP,
		SYSTEM_MBUTTON_DOWN,
		SYSTEM_MBUTTON_UP,
		SYSTEM_RBUTTON_DOWN,
		SYSTEM_RBUTTON_UP,
		SYSTEM_MOUSE_LEAVE,
		SYSTEM_MOUSE_WHEEL,
		SYSTEM_MOUSE_MOVE,
		SYSTEM_KEYBOARD_KEYDOWN,
		SYSTEM_KEYBOARD_KEYUP,
		SYSTEM_KEYBOARD_CHAR,
		WINDOW_RESIZE,
		LOG_MESSAGE,
		INFO_MESSAGE,
		ERROR_MESSAGE,
		NUM_EVENTS
	};

	class IEvent
	{
	public:
		virtual std::wstring	GetEventName() = 0;
		virtual eEvent			GetEventType() = 0;
	};

	typedef std::shared_ptr<IEvent>	EventPtr;
}