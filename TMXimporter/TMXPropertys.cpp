#include "TMXPropertys.h"
#include "XMLHelper.h"

using namespace rapidxml;

TMXPropertys::TMXPropertys(int id)
{
	m_id = id;
}


TMXPropertys::~TMXPropertys()
{
}

int TMXPropertys::getId() const
{
	return m_id;
}

const std::vector<SProperty*>& TMXPropertys::getPropertys()
{
	return m_propertys;
}

const SProperty * TMXPropertys::getPropertyByName(const std::string & name) const
{
	SProperty* r_prop = nullptr;
	for (auto prop : m_propertys)
	{
		if (prop->key == name)
		{
			r_prop = prop;
			break;
		}
	}
	return r_prop;
}

void TMXPropertys::readPropertysNodes(rapidxml::xml_node<>* propertyNode)
{
	for (xml_node<>* child = propertyNode->first_node(); child; child = child->next_sibling())
	{
		if (std::string(child->name()) == "property")
		{
			auto map = XMLHelper::ReadAttributesFromNode(child);
			SProperty* prop = new SProperty();
			prop->key = map["name"];
			prop->value = map["value"];
			m_propertys.push_back(prop);
		}
	}
}
