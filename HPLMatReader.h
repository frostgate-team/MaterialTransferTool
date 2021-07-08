#pragma once

#include <regex>
#include "HPLMaterial.h"

class HPLMatReader
{
	static std::wstring parseTextureUnits(std::string map, std::string line);
	static std::wstring parseGeneralInfo(std::string regex, std::string line);
public:
	static void read(HPLMaterial& mat, std::wstring path);
};

