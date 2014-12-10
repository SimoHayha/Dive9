#include "stdafx.h"
#include "Application.h"

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace Dive9;

int WINAPI WinMain(HINSTANCE h_Inst, HINSTANCE h_PrevInst, LPSTR lpcmdline, int ncmdshow)
{
	Application*	app = Application::GetApplication();
	if (!app)
		return -1;

	app->ConfigureCommandLine(h_Inst, h_PrevInst, lpcmdline, ncmdshow);

	if (!app->ConfigureEngineComponent())
	{
		app->ShutdownEngineComponent();
		return -1;
	}

	app->Initialize();

	app->MessageLoop();

	app->Shutdown();
	app->ShutdownEngineComponent();

	return 0;

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
}