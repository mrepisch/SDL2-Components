#pragma once
#include "rapidxml.hpp"
#include <sstream>
#include <fstream>
#include "Export.h"
#include <streambuf>
#include <map>

class BASIC_KOMPONENT_API XMLHelper
{
public:
	XMLHelper();
	~XMLHelper();
	rapidxml::xml_document<>* loadFile(const char* filename);
	static std::map<std::string, std::string>ReadAttributesFromNode(rapidxml::xml_node<>* node);
	

private:
	rapidxml::xml_document<>* m_doc;
};

