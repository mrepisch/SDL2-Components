#include "TMXObject.h"
#include "XMLHelper.h"

using namespace rapidxml;


TMXObject::TMXObject()
{
}


TMXObject::~TMXObject()
{
	delete m_propertys;
	m_propertys = nullptr;

}

void TMXObject::readObjectNode(rapidxml::xml_node<>* node)
{
	m_attributtes = XMLHelper::ReadAttributesFromNode(node);
	for (xml_node<>* child = node->first_node(); child; child = child->next_sibling())
	{
		std::string nodeName = child->name();
		if (nodeName == "properties")
		{
			m_propertys = new TMXPropertys(std::atoi(m_attributtes["id"].c_str()));
			m_propertys->readPropertysNodes(child);
		}

	}
}

const std::map<std::string, std::string>& TMXObject::getAttributes() const
{
	return m_attributtes;
}

const TMXPropertys * TMXObject::getPropertys()
{
	return m_propertys;
}
