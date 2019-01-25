#pragma once
#include "rapidxml.hpp"
#include "Sprite.h"
#include <vector>
#include "Export.h"

struct BASIC_KOMPONENT_API SAnimTileset
{
	std::string path;
	int tile_height;
	int tile_width;
	int tile_count_x;
	int tile_count_y;
};

struct BASIC_KOMPONENT_API SAnimData
{
	std::string name;
	int start_frame;
	int end_frame;
	int speed;
	bool loop;
};

struct BASIC_KOMPONENT_API SFramePosition
{
	int x;
	int y;
};

class BASIC_KOMPONENT_API SpriteAnimation : public Sprite
{
public:
	SpriteAnimation(const char* xmlFile, SDL_Texture* texture, SDL_Rect rect);
	~SpriteAnimation();

	void startAnim(const std::string& animName);
	void render(SDL_Renderer* renderer);

private:
	void loadXmlFile(const char* xmlFile);
	SAnimTileset* readTilesetNode(rapidxml::xml_node<>* node);
	SAnimData* readAnimDataNode(rapidxml::xml_node<>* node);

	int getAnimIndexFromName(const std::string& name);

	SAnimTileset* m_tileset;
	std::vector< SAnimData*>m_data;
	SDL_Rect m_frame;
	int m_currentAnimIndex = -1;

	int m_currentFrameIndex = -1;
	std::vector<SFramePosition*>m_framePositions;
};

