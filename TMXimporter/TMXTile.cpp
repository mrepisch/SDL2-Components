#include "TMXTile.h"



TMXTile::TMXTile(SDL_Rect& rect, int id)
{
	m_rect = rect;
	m_id = id;
}

TMXTile::~TMXTile()
{
}

int TMXTile::getID()
{
	return m_id;
}

const SDL_Rect & TMXTile::getRect()
{
	return m_rect;
}

void TMXTile::setRect(SDL_Rect rect)
{
	m_rect = rect;
}

void TMXTile::setTilesetID(int tilesetId)
{
	m_tilesetID = tilesetId;
}

int TMXTile::getTilesetID()
{
	return m_tilesetID;
}

