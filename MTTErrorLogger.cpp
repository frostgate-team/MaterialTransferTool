#include "MTTErrorLogger.h"

void MTTErrorLogger::log(std::string message)
{
	std::string err_msg = "Error: " + message;
	MessageBoxA(NULL, err_msg.c_str(), "Error", MB_ICONERROR);
}

void MTTErrorLogger::log(HRESULT hr, std::wstring message)
{
	_com_error error(hr);
	std::wstring err_msg = L"Error: " + message + L"\n" + error.ErrorMessage();
	MessageBoxW(NULL, err_msg.c_str(), L"Error", MB_ICONERROR);
}
