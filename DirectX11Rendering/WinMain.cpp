#include "CustomWin.h"
#include "Window.h"


int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Window wnd(1024, 680, L"DirectX 11 Engine");

	MSG msg;
	BOOL gResult;
	while((gResult = GetMessage(&msg,nullptr,0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if(gResult == -1)
	{
		return -1;
	}

	return msg.wParam;
}
