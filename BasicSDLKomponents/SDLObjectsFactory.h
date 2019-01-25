#pragma once
#include "Export.h"
#include "SDL.h"
#include "SDL_image.h"


class BASIC_KOMPONENT_API SDLObjectsFactory
{
public:
	SDLObjectsFactory();
	~SDLObjectsFactory();
	SDL_Texture* createNewTexture(const char* pathToTexture, SDL_Renderer* renderer);
	
};

