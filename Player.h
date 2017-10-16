#ifndef __Player_H__
#define __Player_H__

#include "GameObject.h"

class Player : public GameObject {
public:
	Player();
	~Player();

	void Load(int x, int y, int x_img, int y_img, int width, int height, std::string textureID);
	void Draw(SDL_Renderer* pRenderer);
	void Update();
	void Clean();

protected:
private:
};

#endif // !__Player_H__


