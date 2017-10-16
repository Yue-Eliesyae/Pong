#ifndef __Application_H__
#define __Application_H__

#include <iostream>
#include <vector>

#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Application
{
public:
	Application();
	~Application();

	bool Init(const char* title, int coordX, int coordY, int width, int height, int flags);
	void Render();
	void Update();
	void HandleEventers();
	void Clean();

	bool running();

protected:

private:
	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;

	int m_currentFrame;
	TextureManager m_textureManager;

	bool m_running;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;
};

#endif // !__Application_H__