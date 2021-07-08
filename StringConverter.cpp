#include "StringConverter.h"

#include <msclr\marshal_cppstd.h>

std::wstring StringConverter::StringToWide(std::string str)
{
	std::wstring converted_wide(str.begin(), str.end());
	return converted_wide;
}

std::string StringConverter::WideToString(std::wstring wide)
{
	std::string converted_string(wide.begin(), wide.end());
	return converted_string;
}
