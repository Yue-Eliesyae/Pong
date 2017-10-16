#include "GameObject.h"

void GameObject::Load(int x, int y, int x_img, int y_img, int width, int height, std::string textureID) {
	m_x = x;
	m_y = y;
	m_xImg = x_img;
	m_yImg = y_img;
	m_width = width;
	m_height = height;
	m_textureID = textureID;

	m_currentFrame = 1;
	m_currentRow = 1;
}

void GameObject::Draw(SDL_Renderer* pRenderer) {
	TextureManager::Instance()->Draw(m_textureID, m_x, m_y, m_xImg, m_yImg, m_width, m_height, pRenderer);
	//TextureManager::Instance()->DrawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::Update() {
	m_x += 1;
}

void GameObject::Clean() {
	std::cout << "Clean GameObject;\n";
}