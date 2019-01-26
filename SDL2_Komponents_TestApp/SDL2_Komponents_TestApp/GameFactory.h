#pragma once
#include <string>
#include "SDL.h"
#include "TMXMap.h"
#include "Player.h"

class GameFactory
{
public:
	GameFactory();
	~GameFactory();
	
	static TMXMap* loadTmxMap(const char* path, SDL_Renderer* renderer);
	static Player* loadPlayer(const TMXMap* map, SDL_Renderer* renderer);
	
	
};

