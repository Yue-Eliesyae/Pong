#ifndef __TextureManager_H__
#define __TextureManager_H__

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <map>

class TextureManager {
public:
	TextureManager();
	~TextureManager();

	static TextureManager* Instance();

	bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void Draw(std::string id, int x, int y, int x_img, int y_img, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

protected:

private:
	static TextureManager* s_pInstance;
	std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif // !__TextureManager_H__


