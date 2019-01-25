
#include "Sprite.h"



Sprite::Sprite(SDL_Texture* texture, SDL_Rect rect)
{
	setTexture(texture);
	m_rect = rect;
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(m_texture);
}

void Sprite::setRenderScaled(bool scaledRender)
{
	m_renderScaled = scaledRender;
}

void Sprite::render(SDL_Renderer* renderer)
{
	if (m_isVisible = true)
	{
		if (m_renderScaled)
		{
			SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);
		}
		else
		{
			SDL_RenderCopy(renderer, m_texture, NULL, NULL);
		}
	}
}

void Sprite::setTexture(SDL_Texture * texture)
{
	if (texture != nullptr)
	{
		m_texture = texture;
	}
}


void Sprite::setRect(SDL_Rect rect)
{
	m_rect = rect;
}



const SDL_Rect & Sprite::getRect()
{
	return m_rect;
}

void Sprite::setZ(int z)
{
	m_z = z;
}

void Sprite::setRect(const SDL_Rect & newRect)
{
	m_rect = newRect;
}

void Sprite::setVisible(bool visible)
{
	m_isVisible = visible;
}

bool Sprite::getIsVisible()
{
	return m_isVisible;
}
