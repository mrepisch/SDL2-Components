#pragma once
#include "rapidxml.hpp"
#include <sstream>
#include <fstream>
#include "Export.h"
#include <streambuf>

class BASIC_KOMPONENT_API XMLHelper
{
public:
	XMLHelper();
	~XMLHelper();
	rapidxml::xml_document<>* loadFile(const char* filename);
	

private:
	rapidxml::xml_document<>* m_doc;
};

