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
		DoFrame();
	}
}
void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, 1.0f, c);
	wnd.Gfx().EndFrame();
}

