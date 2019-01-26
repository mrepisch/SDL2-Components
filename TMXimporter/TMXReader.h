#pragma once
#include "Export.h"
#include "TMXMap.h"



class TMX_IMPORTER_API TMXReader
{
public:
	TMXReader();
	~TMXReader();

	TMXMap* readMapFile(const char* filename, SDL_Renderer* renderer);
};

