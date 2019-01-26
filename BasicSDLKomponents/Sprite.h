#pragma once

#include "Export.h"
#include "IRenderObject.h"

 
class BASIC_KOMPONENT_API Sprite : public IRenderObject
{
public:
	Sprite(SDL_Texture* texture, SDL_Rect rect);

	virtual ~Sprite();

	void setRenderScaled(bool scaledRender);
	virtual void render(SDL_Renderer* renderer);
	void setTexture(SDL_Texture* texture);
	void setRect(SDL_Rect rect);
	const SDL_Rect& getRect();
	void setZ(int z);
	void setRect(const SDL_Rect& newRect);
	void setVisible(bool visible);
	bool getIsVisible();
protected:
	SDL_Texture* m_texture;
	SDL_Rect m_rect;
	bool m_renderScaled = true;
	int m_z;
	bool m_isVisible = true;
};

