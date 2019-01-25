
#include "SDLObjectsFactory.h"
#include <stdio.h>

SDLObjectsFactory::SDLObjectsFactory()
{
}


SDLObjectsFactory::~SDLObjectsFactory()
{
}

SDL_Texture * SDLObjectsFactory::createNewTexture(const char * pathToTexture, SDL_Renderer * renderer)
{
	//The final texture
	SDL_Texture* r_newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(pathToTexture);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", pathToTexture, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		r_newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (r_newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", pathToTexture, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return r_newTexture;
}


