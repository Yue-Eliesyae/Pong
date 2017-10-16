#include "Enemy.h"

void Enemy::Load(int x, int y, int x_img, int y_img, int width, int height, std::string textureID) {

}

void Enemy::Draw(SDL_Renderer* pRenderer) {

}

void Enemy::Update() {
	m_x += 1;
	m_y += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::Clean() {

}