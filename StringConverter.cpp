#include "StringConverter.h"

std::wstring StringConverter::StringToWide(_In_z_ std::string str)
{
	std::wstring converted_wide(str.begin(), str.end());
	return converted_wide;
}

std::string StringConverter::WideToString(_In_z_ std::wstring wide)
{
	std::string converted_string(wide.begin(), wide.end());
	return converted_string;
}