#include "stdafx.h"
#include "FileSystem.h"
#include "Log.h"

using namespace Dive9;

Log::Log()
{
}

Log& Log::Get()
{
	static Log	log;
	return log;
}

bool Log::Open()
{
	FileSystem		fs;
	std::wstring	filename = fs.GetLogFolder() + L"\\Log.txt";
	m_appLog.open(filename.c_str());

	Write(L"Log file opened.");

	return true;
}

bool Log::Write(wchar_t const* textString)
{
	m_appLog << textString << "\n";
#if _DEBUG
	::OutputDebugStringW(textString);
	::OutputDebugStringW(L"\n");
#endif
	return true;
}

bool Log::Write(std::wstring& textString)
{
	Log::Write(textString.c_str());
	m_appLog.flush();
	return true;
}

bool Log::Close()
{
	Write(L"Log file closed.");
	m_appLog.close();
	return true;
}

bool Log::WriteSeparator()
{
	Write(L"------------------------------------------------------------");
	return true;
}