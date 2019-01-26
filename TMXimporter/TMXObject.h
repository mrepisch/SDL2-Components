#pragma once
#include "Export.h"
#include "TMXPropertys.h"
#include "rapidxml.hpp"
#include <map>
#include <string>

class TMX_IMPORTER_API TMXObject
{
public:


	TMXObject();
	~TMXObject();

	void readObjectNode(rapidxml::xml_node<>* node);

	const std::map<std::string, std::string>& getAttributes() const;
	const TMXPropertys* getPropertys();

private:
	std::map<std::string, std::string>m_attributtes;
	TMXPropertys* m_propertys = nullptr;


};

