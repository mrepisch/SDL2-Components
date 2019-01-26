#pragma once
#include <SDL.h>
#include <map>
#include <string>
#include "TMXPropertys.h"
#include "TextureAtlas.h"
#include "rapidxml.hpp"

class TMXTileset
{
public:
	TMXTileset();
	~TMXTileset();

	void readTilesetNode(rapidxml::xml_node<>*node, const char* filename, SDL_Renderer* renderer);

	const std::vector<TMXPropertys*>& getPropertys();

	void render(SDL_Renderer* renderer, int tileId, const SDL_Rect& rect);

private:
	TextureAtlas* m_tileset = nullptr;
	std::vector< TMXPropertys*>m_tilePropertys;
};

