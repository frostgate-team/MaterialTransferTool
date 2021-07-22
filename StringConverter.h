/*
* This is the StringConverter module
* It use to convert different types of strings
*/
#pragma once

#include <string>

class StringConverter
{
public:
	static std::wstring StringToWide(std::string str);
	static std::string WideToString(std::wstring wide);
};

