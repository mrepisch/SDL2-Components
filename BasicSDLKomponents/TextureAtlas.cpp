#include "TextureAtlas.h"
#include "SDLObjectsFactory.h"



TextureAtlas::TextureAtlas(std::string name, SDL_Texture* texture, SDL_Rect tileSize, int totalCount, int columns, int startId)
{
	m_name = name;
	m_startId = startId;
	m_texture = texture;
	m_tileDim = tileSize;
	int x = 0;
	int y = 0;
	int rowCounter = 0;
	for (int i = 0; i < totalCount; ++i)
	{
		STilePositions pos;
		pos.x = x;
		pos.y = y;
		m_tilePositions.push_back(pos);
		++rowCounter;
		if (rowCounter < columns)
		{
			x += tileSize.w;
		}
		else
		{
			rowCounter = 0;
			x = 0;
			y += tileSize.h;
		}
	}
}

TextureAtlas::~TextureAtlas()
{
	SDL_DestroyTexture(m_texture);

}

void TextureAtlas::renderTile(SDL_Renderer * renderer, int id, const SDL_Rect & rect)
{
	SDL_RenderCopy(renderer, m_texture, &getTile(id - m_startId), &rect);
}

const std::string & TextureAtlas::getName()
{
	return m_name;
}

SDL_Rect TextureAtlas::getTile(std::size_t id)
{
	SDL_Rect rect = m_tileDim;

	if (m_tilePositions.size() > id)
	{
		STilePositions pos = m_tilePositions[id];
		rect.x = pos.x;
		rect.y = pos.y;
	}
	return rect;
}



