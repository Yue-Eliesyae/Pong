#include "Player.h"

Player::Player() {

}

Player::~Player() {

}

void Player::Load(int x, int y, int x_img, int y_img, int width, int height, std::string textureID) {
	GameObject::Load(x, y, x_img, y_img, width, height, textureID);
}

void Player::Draw(SDL_Renderer* pRenderer) {
	GameObject::Draw(pRenderer);
}

void Player::Update() {
	m_x -= 1;
}

void Player::Clean() {
	GameObject::Clean();
	std::cout << "Clean Player";

}