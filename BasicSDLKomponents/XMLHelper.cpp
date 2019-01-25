
#include "XMLHelper.h"
#include <iostream>
using namespace rapidxml;

XMLHelper::XMLHelper()
{
}


XMLHelper::~XMLHelper()
{
	delete m_doc;
	m_doc = nullptr;
}

rapidxml::xml_document<>* XMLHelper::loadFile(const char * filename)
{
	std::string buffer;
	std::string line;
	std::ifstream xml_file(filename);
	if (xml_file.is_open())
	{
		while (xml_file.good())
		{
			getline(xml_file, line);
			buffer += line;
		}
		xml_file.close();
	}
	else
	{
		std::cout << "ERROR: xml file not found " << filename << std::endl;
	}
	char *pbuffer = new char[buffer.length() + 1];
	strcpy_s(pbuffer, sizeof(char)*buffer.length() + 1, buffer.c_str());
	pbuffer[buffer.length()] = '\0';
	m_doc = new xml_document<>();
	// create new mesh

	m_doc->parse<0>(pbuffer);
	return m_doc;
}
