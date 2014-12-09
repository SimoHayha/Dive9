#pragma once

#include "stdafx.h"

namespace Dive9
{
	class FileSystem
	{
	public:
		FileSystem();
		virtual ~FileSystem();

		bool	OperatingOnVista();
		bool	OperatingOnXP();

		std::wstring	GetLogFolder();
		std::wstring	GetDataFolder();
		std::wstring	GetModelsFolder();
		std::wstring	GetScriptsFolder();
		std::wstring	GetShaderFolder();
		std::wstring	GetTextureFolder();

		void	SetDataFolder(std::wstring const& folder);
		void	SetModelsFolder(std::wstring const& folder);
		void	SetScriptsFolder(std::wstring const& folder);
		void	SetShaderFolder(std::wstring const& folder);
		void	SetTextureFolder(std::wstring const& folder);

		bool	FileExists(std::wstring const& file);
		bool	FileIsNewer(std::wstring const& file1, std::wstring const& file2);

	private:
		static std::wstring	ms_dataFolder;
		static std::wstring	ms_modelsSubFolder;
		static std::wstring	ms_scriptsSubFolder;
		static std::wstring	ms_shaderSubFolder;
		static std::wstring	ms_textureSubFolder;
	};
}