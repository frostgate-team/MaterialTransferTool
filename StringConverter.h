#pragma once

#include <string>

ref class StringConverter
{
public:
	std::wstring StringToWide(_In_z_ std::string str);
	std::string WideToString(_In_z_ std::wstring wide);
};

