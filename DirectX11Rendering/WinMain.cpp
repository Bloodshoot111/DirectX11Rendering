#include "CustomWin.h"
#include "Window.h"
#include "LittleHelpers.h"



int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	try {
		Window wnd(1024, 680, L"DirectX 11 Engine");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (gResult == -1)
		{
			return -1;
		}

		return msg.wParam;
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



