#ifndef __Enemy_H__
#define __Enemy_H__

#include "GameObject.h"

class Enemy : public GameObject {
public:
	void Load(int x, int y, int x_img, int y_img, int width, int height, std::string textureID);
	void Draw(SDL_Renderer* pRenderer);
	void Update();
	void Clean();

protected:
private:
};

#endif // !__Enemy_H__
