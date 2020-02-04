#pragma once
#include <string>
class LittleHelpers
{
public:
	const static wchar_t* convertCharToWchar(const char* c);
	const static std::string convertWStringToString(const std::wstring& s);
};

