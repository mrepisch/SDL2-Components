#pragma once
#include "Export.h"
#include <string>

class BASIC_KOMPONENT_API PathHelper
{
public:
	PathHelper();
	~PathHelper();

	static std::string getBasePath();

	static std::string removeFilePiceFromPath(const std::string& filePath);

};

