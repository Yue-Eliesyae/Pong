#include "Application.h"

Application* g_app = 0;

int main(int argc, char* argv[])
{
	g_app = new Application();
	g_app->Init("Stdio", 100, 100, 640, 480, 0);

	while (g_app->running())
	{
		g_app->HandleEventers();
		g_app->Update();
		g_app->Render();
		
		SDL_Delay(10);
	}
	g_app->Clean();

	return 0;
}