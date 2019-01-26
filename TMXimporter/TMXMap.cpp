#include "TMXMap.h"
#include "XMLHelper.h"
#include "PathHelper.h"
#include "SDLObjectsFactory.h"
#include "TMXPropertys.h"

using namespace rapidxml;

TMXMap::TMXMap()
{
}


TMXMap::~TMXMap()
{
	for (std::size_t i = 0; i < m_layers.size(); ++i)
	{
		delete m_layers[i];
		m_layers[i] = nullptr;
	}
	m_layers.clear();
	delete m_tilesets;
	m_tilesets = nullptr;
	delete m_propertys;
	m_propertys = nullptr;
	
}

void TMXMap::addLayer(TMXLayer * layer)
{
}

const TMXLayer * TMXMap::getLayerByID(int id)
{
	TMXLayer* r_layer = nullptr;
	for (auto layer : m_layers)
	{
		if (layer->getPropertys()->getId() == id)
		{
			r_layer = layer;
			break;
		}
	}
	return r_layer;
}

const TMXLayer * TMXMap::getLayerByName(std::string layername)
{
	TMXLayer* r_layer = nullptr;
	for (auto layer : m_layers)
	{
		if (layer->getAttribute("name") == layername)
		{
			r_layer = layer;
			break;
		}
	}
	return r_layer;
}

void TMXMap::readMapNode(rapidxml::xml_node<>* mapNode, const char* filename, SDL_Renderer* renderer)
{
	XMLHelper helper;
	m_attributes = helper.ReadAttributesFromNode(mapNode);
	for (xml_node<>* child = mapNode->first_node(); child; child = child->next_sibling())
	{
		if (std::string(child->name()) == "tileset")
		{
			//m_tilesets.push_back(readTilesetNode(child, filename, renderer));
			m_tilesets = new TMXTileset();
			m_tilesets->readTilesetNode(child, filename, renderer);
			bool test = false;

		}
		else if (std::string(child->name()) == "layer")
		{
			TMXLayer* layer = new TMXLayer(std::atoi(m_attributes["width"].c_str()),
				std::atoi(m_attributes["height"].c_str()),
				std::atoi(m_attributes["tilewidth"].c_str()),
				std::atoi(m_attributes["tileheight"].c_str()));
			layer->readNode(child);
			m_layers.push_back(layer);
		}
		else if (std::string(child->name()) == "properties")
		{
			m_propertys = new TMXPropertys(-1);
			m_propertys->readPropertysNodes(child);
		}
		else if (std::string(child->name()) == "objectgroup")
		{
			TMXObjectGroup* objGroup = new TMXObjectGroup();
			objGroup->readObjectGroupNode(child);
			m_objectGroups.push_back(objGroup);
		}
	}

}

void TMXMap::render(SDL_Renderer * renderer)
{
	for (auto layer : m_layers)
	{
		auto tiles = layer->getTiles();
		for (auto tile : tiles)
		{
			if (tile->getTilesetID() >= 0)
			{
				SDL_Rect rect = tile->getRect();
				rect.x = rect.x + m_tilemapOffset.x;
				rect.y = rect.y + m_tilemapOffset.y;
				tile->setRect(rect);
				m_tilesets->render(renderer, tile->getTilesetID(), tile->getRect());
			}
		}
	}
	m_tilemapOffset.x = 0;
	m_tilemapOffset.y = 0;
}

const std::vector<TMXLayer*>& TMXMap::getLayers()
{
	return m_layers;
}

const std::vector<TMXObjectGroup*>& TMXMap::getObjectGroups()
{
	return m_objectGroups;
}

const std::map<std::string, std::string>& TMXMap::getAttributtes()
{
	return m_attributes;
}

const TMXTileset * TMXMap::getTileset()
{
	return m_tilesets;
}

const TMXPropertys * TMXMap::getPropoertys()
{
	return m_propertys;
}

const TMXObjectGroup * TMXMap::getObjectgroupByName(const std::string & groupName) const
{
	TMXObjectGroup* r_group = nullptr;
	for (auto group : m_objectGroups)
	{
		if (group->getAttributes().at("name") == groupName)
		{
			r_group = group;
			break;
		}
	}
	return r_group;
}

