/*
* This is the .mat files reader header.
* We are using a basic C++ regex, so the search implementation is actually quite big.
*/
#pragma once

#include <regex>
#include "HPLMaterial.h"

class HPLMatReader
{
	/// <summary>
	/// Rules for <Texture units> section parsing
	/// </summary>
	/// <param name="regex"></param>
	/// <param name="line"></param>
	/// <returns></returns>
	static std::wstring parseTextureUnits(std::string regex, std::string line);
	static std::wstring parseGeneralInfo(std::string regex, std::string line);
public:
	static void __fastcall read(_Inout_ HPLMaterial& mat, _In_ std::wstring path);
};

