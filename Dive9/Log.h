#pragma once

#include "stdafx.h"

namespace Dive9
{
	class Log
	{
	public:
		static Log&	Get();

		bool	Open();
		bool	Close();

		bool	Write(wchar_t const* textString);
		bool	Write(std::wstring& textString);
		bool	WriteSeparator();

	protected:
		Log();

		std::wofstream	m_appLog;
	};
}