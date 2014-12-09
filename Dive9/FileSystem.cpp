#include "stdafx.h"

#include <ShlObj.h>
#include <VersionHelpers.h>

#include "FileSystem.h"

using namespace Dive9;

std::wstring	FileSystem::ms_dataFolder = L"../Data/";
std::wstring	FileSystem::ms_modelsSubFolder = L"Models/";
std::wstring	FileSystem::ms_scriptsSubFolder = L"Scripts/";
std::wstring	FileSystem::ms_shaderSubFolder = L"Shaders/";
std::wstring	FileSystem::ms_textureSubFolder = L"Textures/";

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

bool FileSystem::OperatingOnVista()
{
	return IsWindowsVistaOrGreater();

	//OSVERSIONINFO	osver;
	//memset(&osver, 0, sizeof(OSVERSIONINFO));
	//osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	//if (!GetVersionEx(&osver))
	//	return false;

	//if (osver.dwPlatformId == VER_PLATFORM_WIN32_NT && osver.dwMajorVersion >= 6)
	//	return true;

	//return false;
}

bool FileSystem::OperatingOnXP()
{
	return IsWindowsXPOrGreater();

	//OSVERSIONINFO	osver;
	//memset(&osver, 0, sizeof(OSVERSIONINFO));
	//osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	//if (!GetVersionEx(&osver))
	//	return false;

	//if (osver.dwPlatformId == VER_PLATFORM_WIN32_NT && osver.dwMajorVersion >= 5)
	//	return true;

	//return false;
}

std::wstring FileSystem::GetLogFolder()
{
	wchar_t	buffer[MAX_PATH];

	HRESULT	hr = SHGetFolderPath(nullptr, CSIDL_LOCAL_APPDATA, nullptr, SHGFP_TYPE_CURRENT, buffer);

	std::wstring	result = buffer;

	return result;
}

std::wstring FileSystem::GetDataFolder()
{
	return ms_dataFolder;
}

std::wstring FileSystem::GetModelsFolder()
{
	return ms_dataFolder + ms_modelsSubFolder;
}

std::wstring FileSystem::GetScriptsFolder()
{
	return ms_dataFolder + ms_scriptsSubFolder;
}

std::wstring FileSystem::GetShaderFolder()
{
	return ms_dataFolder + ms_shaderSubFolder;
}

std::wstring FileSystem::GetTextureFolder()
{
	return ms_dataFolder + ms_textureSubFolder;
}

void FileSystem::SetDataFolder(std::wstring const& folder)
{
	ms_dataFolder = folder;
}

void FileSystem::SetModelsFolder(std::wstring const& folder)
{
	ms_modelsSubFolder = folder;
}

void FileSystem::SetScriptsFolder(std::wstring const& folder)
{
	ms_scriptsSubFolder = folder;
}

void FileSystem::SetShaderFolder(std::wstring const& folder)
{
	ms_shaderSubFolder = folder;
}

void FileSystem::SetTextureFolder(std::wstring const& folder)
{
	ms_textureSubFolder = folder;
}

bool FileSystem::FileExists(std::wstring const& file)
{
	DWORD	dwAttrib = GetFileAttributes(file.c_str());

	return (dwAttrib != INVALID_FILE_ATTRIBUTES && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

bool FileSystem::FileIsNewer(std::wstring const& file1, std::wstring const& file2)
{
	HANDLE	handle1 = INVALID_HANDLE_VALUE;
	HANDLE	handle2 = INVALID_HANDLE_VALUE;

	handle1 = CreateFileW(file1.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	handle2 = CreateFileW(file2.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	FILETIME	fileTime1;
	FILETIME	fileTime2;

	GetFileTime(handle1, nullptr, nullptr, &fileTime1);
	GetFileTime(handle2, nullptr, nullptr, &fileTime2);

	CloseHandle(handle1);
	CloseHandle(handle2);

	if (fileTime1.dwHighDateTime > fileTime2.dwHighDateTime)
		return true;
	else if (fileTime1.dwHighDateTime == fileTime2.dwHighDateTime)
		return fileTime1.dwLowDateTime > fileTime2.dwHighDateTime;
	return false;
}