#include "App.h"

App::App()
	:
	wnd(800,600,L"DirectX11 Engine")
{}

int App::Go()
{

	while(true)
	{
		if(const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
	}
}
void App::DoFrame()
{
	
}

