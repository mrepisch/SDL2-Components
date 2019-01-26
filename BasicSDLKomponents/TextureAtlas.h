#pragma once
#include <SDL.h>
#include <vector>
#include "Export.h"


class BASIC_KOMPONENT_API TextureAtlas
{
public:
	TextureAtlas(std::string name, SDL_Texture* texture, SDL_Rect tileSize, int totalCount, int columns, int startId = 0 );
	~TextureAtlas();
	void renderTile(SDL_Renderer* renderer, int id, const SDL_Rect& rect );
	
	const std::string& getName();


private:
	struct STilePositions
	{
		int x;
		int y;
	};

	std::string m_name;
	SDL_Rect getTile(std::size_t id);
	SDL_Rect m_tileDim;
	SDL_Texture* m_texture;
	int m_startId = 0;
	std::vector<STilePositions>m_tilePositions;
};

