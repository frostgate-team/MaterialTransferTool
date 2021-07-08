#pragma once

#include "StringConverter.h"
#include <comdef.h>

class MTTErrorLogger
{
public:
	static void log(std::string message);
	static void log(HRESULT hr, std::wstring message);
};

