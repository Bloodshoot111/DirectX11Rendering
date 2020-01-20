#include <Windows.h>
#include <string>


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
	wc.lpfnWndProc = DefWindowProc;
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
	while(true)
	{
		
	}
	return 0;
}
