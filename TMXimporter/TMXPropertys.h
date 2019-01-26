#pragma once
#include <rapidxml.hpp>
#include <vector>
#include <string>
#include "Export.h"


struct TMX_IMPORTER_API SProperty
{
	std::string key;
	std::string value;
};

class TMX_IMPORTER_API TMXPropertys
{
public:
	TMXPropertys(int id);
	~TMXPropertys();
	int getId() const;
	const std::vector<SProperty*>& getPropertys();
	const SProperty* getPropertyByName(const std::string& name) const;
	void readPropertysNodes(rapidxml::xml_node<>* propertyNode);

private:
	int m_id;
	std::vector<SProperty*>m_propertys;
};

