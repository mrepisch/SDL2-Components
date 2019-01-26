#pragma once
#include "SDL.h"
#include <string>
#include <vector>
#include <map>
#include "Export.h"
#include "TMXPropertys.h"
#include "rapidxml.hpp"
#include "TMXTile.h"

class TMX_IMPORTER_API TMXLayer
{
public:
	TMXLayer(int tileCount_x, int tileCount_y, int tileWidth, int tileHeight);
	~TMXLayer();

	void readNode(rapidxml::xml_node<>*layernode);

	const std::vector<TMXTile*>& getTiles();
	const TMXPropertys* getPropertys();

	const std::string& getAttribute(const std::string& key);
	

private:

	std::map<std::string, std::string>m_attributes;
	TMXPropertys* m_propertys = nullptr;
	std::vector<TMXTile*>m_tiles;

};

