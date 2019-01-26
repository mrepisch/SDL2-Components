#include "TMXObjectGroup.h"
#include "XMLHelper.h"

using namespace rapidxml;

TMXObjectGroup::TMXObjectGroup()
{
}


TMXObjectGroup::~TMXObjectGroup()
{
	for (auto obj : m_objects)
	{
		delete obj;
	}
	m_objects.clear();
	delete m_propertys;
	m_propertys = nullptr;
}

void TMXObjectGroup::readObjectGroupNode(rapidxml::xml_node<>* node)
{
	m_attributes = XMLHelper::ReadAttributesFromNode(node);
	for (xml_node<>* child = node->first_node(); child; child = child->next_sibling())
	{
		std::string nodeName = std::string(child->name());
		if (nodeName == "properties")
		{
			m_propertys = new TMXPropertys(std::atoi(m_attributes["id"].c_str()));
			m_propertys->readPropertysNodes(child);
		}
		else if (nodeName == "object")
		{
			TMXObject* obj = new TMXObject();
			obj->readObjectNode(child);
			m_objects.push_back(obj);
		}
	}
}

const TMXPropertys * TMXObjectGroup::getPropertys()
{
	return m_propertys;
}

const std::map<std::string, std::string>& TMXObjectGroup::getAttributes()
{
	return m_attributes;
}

const std::vector<TMXObject*>& TMXObjectGroup::getObjects() const
{
	return m_objects;
}
