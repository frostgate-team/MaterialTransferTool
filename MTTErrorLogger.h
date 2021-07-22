/*
* This is the MTTErrorLogger class
* It use to log errors thrown by WinAPI in tool
*/
#pragma once

#include "StringConverter.h"
#include <comdef.h>

class MTTErrorLogger
{
public:
	/// <summary>
	/// Log message with std::string
	/// </summary>
	/// <param name="message"> - Error message in std::string format</param>
	static void log(std::string message);
	/// <summary>
	/// Log message wisth std::wstring
	/// </summary>
	/// <param name="hr"> - Windows result codes</param>
	/// <param name="message"> - Error message in std::wstring format</param>
	static void log(HRESULT hr, std::wstring message);
};

