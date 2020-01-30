#pragma once
#include "Window.h"
#include "CustomTimer.h"

class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	CustomTimer timer;
};

