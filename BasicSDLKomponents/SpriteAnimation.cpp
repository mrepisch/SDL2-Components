
#include "SpriteAnimation.h"
#include "XMLHelper.h"
#include <iostream>

using namespace std;
using namespace rapidxml;


SpriteAnimation::SpriteAnimation(const char * xmlFile, SDL_Texture * texture, SDL_Rect rect) : Sprite(texture, rect)
{
	loadXmlFile(xmlFile);
	m_frame.x = 0;
	m_frame.y = 0;
	m_frame.w = m_tileset->tile_width;
	m_frame.h = m_tileset->tile_height;
	int x = 0; 
	int y = 0;
	int rowCounter = 0;
	for (int index = 0; index <= m_tileset->tile_count_x * m_tileset->tile_count_y; ++index)
	{
		SFramePosition* pos = new SFramePosition();
		pos->x = x;
		pos->y = y;
		m_framePositions.push_back(pos);
		++rowCounter;
		if (rowCounter < m_tileset->tile_count_x)
		{
			x += m_tileset->tile_width;
		}
		else
		{
			rowCounter = 0;
			y += m_tileset->tile_height;
			x = 0;
		}
	}
	startAnim("attack");
}

SpriteAnimation::~SpriteAnimation()
{
}

void SpriteAnimation::startAnim(const std::string & animName)
{
	int animIndex = getAnimIndexFromName(animName);
	if (animIndex >= 0)
	{
		m_currentAnimIndex = animIndex;
		m_currentFrameIndex = m_data[m_currentAnimIndex]->start_frame;
	}
}

void SpriteAnimation::render(SDL_Renderer * renderer)
{
	if (m_currentAnimIndex >= 0 && m_currentFrameIndex >= 0)
	{
		SAnimData* data = m_data[m_currentAnimIndex];
		if (m_currentFrameIndex + 1 > data->end_frame)
		{
			m_currentFrameIndex = data->start_frame;
		}
		else
		{
			++m_currentFrameIndex;
		}
		m_frame.x = m_framePositions[m_currentFrameIndex]->x;
		m_frame.y = m_framePositions[m_currentFrameIndex]->y;
		SDL_RenderCopy(renderer, m_texture, &m_frame, &m_rect);
	}
}

void SpriteAnimation::loadXmlFile(const char * xmlFile)
{
	XMLHelper helper;
	xml_document<>* doc = helper.loadFile(xmlFile);
	xml_node<>* node = doc->first_node("anims");
	for (auto child = node->first_node(); child; child = child->next_sibling())
	{
		if (std::string(child->name()) == "tileset")
		{
			m_tileset = readTilesetNode(child);
		}
		else if (std::string(child->name()) == "anim")
		{
			m_data.push_back(readAnimDataNode(child));
		}
	}

}

SAnimTileset* SpriteAnimation::readTilesetNode(rapidxml::xml_node<>* node)
{
	SAnimTileset* r_tileSetData = new SAnimTileset();
	for (auto child = node->first_node(); child; child = child->next_sibling())
	{
		cout << child->value();
		if (string(child->name()) == "path")
		{
			r_tileSetData->path = child->value();
		}
		else if (string(child->name()) == "tile_height")
		{
			r_tileSetData->tile_height = stoi( child->value() );
		}
		else if (string(child->name()) == "tile_width")
		{
			r_tileSetData->tile_width = stoi(child->value());
		}
		else if (string(child->name()) == "tile_count_x")
		{
			r_tileSetData->tile_count_x = stoi(child->value());
		}
		else if (string(child->name()) == "tile_count_y")
		{
			r_tileSetData->tile_count_y = stoi(child->value());
		}
	}
	return r_tileSetData;
}

SAnimData* SpriteAnimation::readAnimDataNode(rapidxml::xml_node<>* node)
{
	SAnimData* r_data = new SAnimData();
	for (auto child = node->first_node(); child; child = child->next_sibling())
	{
		cout << child->name() << endl;
		if (string(child->name()) == "name")
		{
			r_data->name = child->value();
		}
		else if (string(child->name()) == "start_frame")
		{
			r_data->start_frame = stoi(child->value());
		}
		else if (string(child->name()) == "end_frame")
		{
			r_data->end_frame = stoi(child->value());
		}
		else if (string(child->name()) == "speed")
		{
			r_data->speed = stoi(child->value());
		}
		else if (string(child->name()) == "loop")
		{
			r_data->loop = true;
			string value = child->value();
			if (value == "False" || value == "false")
			{
				r_data->loop = false;
			}
		}
	}
	return r_data;
}

int SpriteAnimation::getAnimIndexFromName(const std::string& name)
{
	int r_index = -1;
	for ( std::size_t i = 0; i < m_data.size(); ++i)
	{
		if (m_data[i]->name == name)
		{
			r_index = i;
			break;
		}
	}
	return r_index;
}
