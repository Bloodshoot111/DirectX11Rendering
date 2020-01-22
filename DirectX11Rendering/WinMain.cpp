#include "CustomWin.h"
#include "Window.h"
#include "LittleHelpers.h"
#include "App.h"


int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	try {

		return App{}.Go();
	}
	catch(const CustomException& e)
	{
		MessageBox(nullptr, LittleHelpers::convertCharToWchar(e.what()), LittleHelpers::convertCharToWchar(e.GetType()), MB_OK |MB_ICONEXCLAMATION);
	}
	catch(const std::exception& e)
	{
		MessageBox(nullptr, (LittleHelpers::convertCharToWchar(e.what())), L"Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch(...)
	{
		MessageBox(nullptr, L"No details available", L"Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}



