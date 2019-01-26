#pragma once
#include "Export.h"
#include "SDL.h"

class TMX_IMPORTER_API TMXTile
{
public:
	TMXTile(SDL_Rect& rect, int id = -1);
	~TMXTile();

	int getID();
	const SDL_Rect& getRect();
	void setRect(SDL_Rect rect);

	void setTilesetID(int tilesetId);
	int getTilesetID();
	
private:

	int m_id = -1;
	int m_tilesetID = -1;
	SDL_Rect m_rect;
};

