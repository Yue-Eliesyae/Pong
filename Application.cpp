#include "Application.h"

bool Application::Init(const char* title, int coordX, int coordY, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Sdl Init success;\n";
		m_pWindow = SDL_CreateWindow(title, coordX, coordY, width, height, flags);

		if (m_pWindow != 0) {
			std::cout << "Window Creation Success;\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {
				std::cout << "Renderer Creation Success;\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else {
				std::cout << "Renderer Init Fail;\n";
				return false;
			}
		}
		else {
			std::cout << "Window Init Fail;\n";
			return false;
		}
	}
	else {
		std::cout << "Sdl Init Fail;\n";
		return false;
	}
	
	if (!TextureManager::Instance()->Load("../Data/spr_data.png", "data", m_pRenderer)) {
		std::cout << "Can't load img!";
		return false;
	}
	m_go = new GameObject();
	m_player = new Player();
	m_enemy = new Enemy();

	m_go->Load(10, 10, 300, 250, 50, 180, "data");
	//m_player->Load(0, 0, 300, 300, "data");

	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_go);

	std::cout << "Init Success;\n";
	m_running = true;

	return true;
}

void Application::Render()
{
	SDL_RenderClear(m_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->Draw(m_pRenderer);
	}

	/*TextureManager::Instance()->Draw("animate", 0, 0, 128, 82, m_pRenderer);
	TextureManager::Instance()->DrawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);*/

	/*m_textureManager.Draw("animate", 0, 0, 128, 82, m_pRenderer);
	m_textureManager.DrawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);*/

	SDL_RenderPresent(m_pRenderer);
}

void Application::Update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->Update();
	}
}

void Application::HandleEventers()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;

		default:
			break;
		}
	}
}

bool Application::running()
{
	return m_running;
}

void Application::Clean()
{
	std::cout << "Cleaning game;\n";

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

Application::Application(){

}

Application::~Application(){

}