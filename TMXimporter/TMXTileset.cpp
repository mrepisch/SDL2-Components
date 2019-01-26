#include "TMXTileset.h"
#include "XMLHelper.h"
#include "PathHelper.h"
#include "SDLObjectsFactory.h"

using namespace rapidxml;

TMXTileset::TMXTileset()
{
}


TMXTileset::~TMXTileset()
{
}

void TMXTileset::readTilesetNode(rapidxml::xml_node<>* node, const char * filename, SDL_Renderer * renderer)
{
	XMLHelper helper;
	auto tilesetAttributesInTmxMap = helper.ReadAttributesFromNode(node);
	xml_document<>*tilesetdoc = helper.loadFile((PathHelper::removeFilePiceFromPath(filename) + "/" + tilesetAttributesInTmxMap["source"]).c_str());
	xml_node<>* first = tilesetdoc->first_node();
	auto tilesetAttrmap = helper.ReadAttributesFromNode(first);
	SDLObjectsFactory fac;
	std::map<std::string, std::string> imageAttrMap;
	for (xml_node<>* child = first->first_node(); child; child = child->next_sibling())
	{
		if (std::string(child->name()) == "image")
		{
			imageAttrMap = helper.ReadAttributesFromNode(child);
			SDL_Rect tilesize;
			tilesize.x = 0;
			tilesize.y = 0;
			tilesize.w = std::atoi(tilesetAttrmap["tilewidth"].c_str());
			tilesize.h = std::atoi(tilesetAttrmap["tileheight"].c_str());
			m_tileset = new TextureAtlas(
				tilesetAttrmap["name"],
				fac.createNewTexture((PathHelper::removeFilePiceFromPath(filename) + "/" + imageAttrMap["source"]).c_str(), renderer),
				tilesize,
				std::atoi(tilesetAttrmap["tilecount"].c_str()),
				std::atoi(tilesetAttrmap["columns"].c_str()),
				std::atoi(tilesetAttributesInTmxMap["firstgid"].c_str()));
		}
		else if (std::string(child->name()) == "tile")
		{
			auto tileattrs = XMLHelper::ReadAttributesFromNode(child);
			int id = std::atoi(tileattrs["id"].c_str());
			xml_node<>* propertysNode = child->first_node("properties");
			TMXPropertys* propertys = new TMXPropertys(id);
			propertys->readPropertysNodes(propertysNode);
			m_tilePropertys.push_back(propertys);

		}
	}



}

const std::vector<TMXPropertys*>& TMXTileset::getPropertys()
{
	return m_tilePropertys;
}

void TMXTileset::render(SDL_Renderer * renderer, int tileId, const SDL_Rect & rect)
{
	if (m_tileset != nullptr)
	{
		m_tileset->renderTile(renderer, tileId, rect);
	}
}
