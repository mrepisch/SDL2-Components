#include "TMXLayer.h"

#include "XMLHelper.h"

#include <iostream>
using namespace rapidxml;

TMXLayer::TMXLayer(int tileCount_x, int tileCount_y, int tileWidth, int tileHeight)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = tileWidth;
	rect.h = tileHeight;
	int totalTileCount = tileCount_x * tileCount_y;
	int rowCounter = 0;
	for (int index = 0; index < totalTileCount; ++index)
	{
		TMXTile* tile = new TMXTile(rect, index);
		m_tiles.push_back(tile);
		++rowCounter;
		if (rowCounter < tileCount_x)
		{
			rect.x += tileWidth;
		}
		else
		{
			rect.x = 0;
			rect.y += tileHeight;
			rowCounter = 0;
		}
	}
}

TMXLayer::~TMXLayer()
{
	for (std::size_t i = 0; i < m_tiles.size(); ++i)
	{
		delete m_tiles[i];
		m_tiles[i] = 0;
	}
	m_tiles.clear();
	delete m_propertys;
	m_propertys = nullptr;
}

void TMXLayer::readNode(rapidxml::xml_node<>* layernode)
{
	m_attributes = XMLHelper::ReadAttributesFromNode(layernode);
	for (xml_node<>* child = layernode->first_node(); child; child = child->next_sibling())
	{
		if (std::string(child->name()) == "properties")
		{
			m_propertys = new TMXPropertys(std::atoi(m_attributes["id"].c_str()));
			m_propertys->readPropertysNodes(child);
		}
		else if (std::string(child->name()) == "data")
		{
			int tileCounter = 0;
			for (xml_node<>* tilenode = child->first_node(); tilenode; tilenode = tilenode->next_sibling())
			{
				auto tileAttr = XMLHelper::ReadAttributesFromNode(tilenode);
				if (!tileAttr.empty())
				{
					m_tiles[tileCounter]->setTilesetID(std::atoi(tileAttr["gid"].c_str()));
				}
				++tileCounter;
			}
		}
	}
}

const std::vector<TMXTile*>& TMXLayer::getTiles()
{
	return m_tiles;
}

const TMXPropertys * TMXLayer::getPropertys()
{
	return m_propertys;
}

const std::string & TMXLayer::getAttribute(const std::string & key)
{
	std::string r_attr;
	auto iter = m_attributes.begin();
	while (iter != m_attributes.end())
	{
		if (iter->first == key)
		{
			r_attr = iter->second;
			break;
		}
		iter++;
	}
	return r_attr;
}


