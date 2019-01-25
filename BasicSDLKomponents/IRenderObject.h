#pragma once

#include "SDL.h"
#include "Export.h"

class BASIC_KOMPONENT_API IRenderObject
{
public:
	virtual void setRect(const SDL_Rect& newRect) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual void setVisible(bool visible) = 0;
	virtual bool getIsVisible() = 0;
	virtual void setZ(int z) = 0;
	virtual void setTexture(SDL_Texture* texture) = 0;

};