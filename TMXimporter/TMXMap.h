#pragma once

#include "rapidxml.hpp"
#include "Export.h"
#include "TMXLayer.h"
#include "TMXTileset.h"
#include <vector>
#include <string>
#include <map>
#include <IRenderObject.h>
#include "TMXObjectGroup.h"


class TMX_IMPORTER_API TMXMap : public IRenderObject
{
public:
	TMXMap();
	~TMXMap();

	void addLayer(TMXLayer* layer);
	const TMXLayer* getLayerByID(int id);
	const TMXLayer* getLayerByName(std::string layername);

	void readMapNode(rapidxml::xml_node<>*mapNode, const char* filename, SDL_Renderer* renderer);

	void render(SDL_Renderer* renderer);

	void setRect(const SDL_Rect& newRect) { m_tilemapOffset = newRect; };
	const SDL_Rect& getRect() { return m_tilemapOffset; }
	void setVisible(bool visible) {};
	bool getIsVisible() {
		return true;
	};
	void setZ(int z) {};
	void setTexture(SDL_Texture* texture) {};

	const std::vector<TMXLayer*>& getLayers();
	const std::vector<TMXObjectGroup*>&getObjectGroups();
	const std::map<std::string, std::string>& getAttributtes();
	const TMXTileset* getTileset();
	const TMXPropertys* getPropoertys();
	const TMXObjectGroup* getObjectgroupByName(const std::string& groupName) const ;


protected:
	std::vector<TMXLayer*> m_layers;
	std::vector<TMXObjectGroup*>m_objectGroups;
	std::map<std::string, std::string>m_attributes;
	TMXTileset*m_tilesets = nullptr;
	TMXPropertys* m_propertys = nullptr;
private:
	SDL_Rect m_tilemapOffset;
	

};

