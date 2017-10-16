#ifndef __GameObject_H__
#define __GameObject_H__

#include <SDL.h>

#include <iostream>

#include "TextureManager.h"

class GameObject {
public:
	virtual void Load(int x, int y, int x_img, int y_img, int width, int height, std::string textureID);
	virtual void Draw(SDL_Renderer* pRenderer);
	virtual void Update();
	virtual void Clean();

protected:
	std::string m_textureID;

	int m_currentFrame,
		m_currentRow;

	int m_x,
		m_y;
	int m_xImg,
		m_yImg;

	int m_width,
		m_height;

private:
};

#endif // !__GameObject_H__

