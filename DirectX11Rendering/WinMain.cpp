#include <Windows.h>
#include <sstream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if(wParam == 'F')
		{
			SetWindowText(hWnd,L"Test");
		}
		break;
	case WM_CHAR:
	{
		static std::wstring title;
		title.push_back(char(wParam));
		SetWindowText(hWnd, title.c_str());
	}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	const std::wstring className = L"DX11";
	const std::wstring windowName = L"DX11Window";
	const LPCWSTR pClassName = className.c_str();
	const LPCWSTR lpWindowName = windowName.c_str();
	
	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	//Create Window Instance
	HWND hWnd = CreateWindowEx(
		0, pClassName, lpWindowName,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,  200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);
	//show the window
	ShowWindow(hWnd, SW_SHOW);
	//message pump
	MSG msg;
	BOOL gResult;
	while((gResult = GetMessage(&msg,nullptr, 0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if(gResult == -1)
	{
		return -1;
	} else
	{
		return msg.wParam;
	}
}
