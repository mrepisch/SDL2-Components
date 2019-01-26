#pragma once
#include "rapidxml.hpp"
#include <vector>
#include <map>
#include <string>
#include "TMXPropertys.h"
#include "TMXObject.h"
#include "Export.h"

class TMX_IMPORTER_API TMXObjectGroup
{
public:
	TMXObjectGroup();
	~TMXObjectGroup();

	void readObjectGroupNode(rapidxml::xml_node<>* node);
	const TMXPropertys* getPropertys();
	const std::map<std::string, std::string>& getAttributes();
	const std::vector<TMXObject*>& getObjects() const ;


private:

	TMXPropertys* m_propertys;
	std::map<std::string, std::string>m_attributes;
	std::vector<TMXObject*>m_objects;

};

