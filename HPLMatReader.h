/*
* This is the .mat files reader header.
* We are using a basic C++ regex, so the search implementation is actually quite big.
* 
* TODO: Cut the parsing implementation
*/
#pragma once

#include <regex>
#include "HPLMaterial.h"

class HPLMatReader
{
	/// <summary>
	/// Rules for Texture units section parsing
	/// </summary>
	/// <param name="regex"> - Parameter you need to find in Texture units tag</param>
	/// <param name="line"> - Line to find in</param>
	/// <returns>Content of tag</returns>
	static std::wstring parseTextureUnits(std::string regex, std::string line);
	/// <summary>
	/// Rules for Main section parsing
	/// </summary>
	/// <param name="regex"> - Parameter Tag you need to find in Main tag</param>
	/// <param name="line"> - Line to find in</param>
	/// <returns> Content of tag</returns>
	static std::wstring parseGeneralInfo(std::string regex, std::string line);
public:
	/// <summary>
	/// Reads given material to HPLMaterial
	/// </summary>
	/// <param name="mat"> - link to HPLMaterial object</param>
	/// <param name="path"> - path to .mat file</param>
	static void __fastcall read(_Inout_ HPLMaterial& mat, _In_ std::wstring path);
};

