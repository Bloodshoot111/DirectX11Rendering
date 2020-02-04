#include "LittleHelpers.h"
#include <string>
#include <clocale>
#include <locale>
#include <vector>

const wchar_t* LittleHelpers::convertCharToWchar(const char* c)
{
	size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	size_t outSize;
	mbstowcs_s(&outSize, wc, cSize, c, cSize - 1);
	return wc;
}

const std::string LittleHelpers::convertWStringToString(const std::wstring& ws)
{
	std::setlocale(LC_ALL, "");
	const std::locale locale("");
	typedef std::codecvt<wchar_t, char, std::mbstate_t> converter_type;
	const converter_type& converter = std::use_facet<converter_type>(locale);
	std::vector<char> to(ws.length() * converter.max_length());
	std::mbstate_t state;
	const wchar_t* from_next;
	char* to_next;
	const converter_type::result result = converter.out(state, ws.data(), ws.data() + ws.length(), from_next, &to[0], &to[0] + to.size(), to_next);
	if (result == converter_type::ok or result == converter_type::noconv)
	{
		const std::string s(&to[0], to_next);
		return s;
	}

	 return nullptr;
}
