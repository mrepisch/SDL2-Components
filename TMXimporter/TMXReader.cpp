#include "TMXReader.h"
#include "XMLHelper.h"

using namespace rapidxml;
TMXReader::TMXReader()
{
}


TMXReader::~TMXReader()
{
}

TMXMap * TMXReader::readMapFile(const char * filename, SDL_Renderer* renderer)
{
	TMXMap* r_map = new TMXMap();
	XMLHelper helper;
	xml_document<>* doc = helper.loadFile(filename);
	xml_node<>* mapNode = doc->first_node();
	if (std::string(mapNode->name()) == "map")
	{
		r_map->readMapNode(mapNode,filename,renderer);
	}
	return r_map;
}
