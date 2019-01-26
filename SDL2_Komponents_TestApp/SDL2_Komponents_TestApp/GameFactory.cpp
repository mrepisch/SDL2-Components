#include "pch.h"
#include "GameFactory.h"
#include "TMXReader.h"


const std::string S_InteractiveObjectGroupName = "interactive";

GameFactory::GameFactory()
{
}


GameFactory::~GameFactory()
{
}

TMXMap * GameFactory::loadTmxMap(const char * path, SDL_Renderer * renderer)
{
	TMXReader reader;
	return reader.readMapFile(path, renderer);
}

Player * GameFactory::loadPlayer(const TMXMap * map, SDL_Renderer* renderer)
{
	Player* r_player = nullptr;
	const TMXObjectGroup* group = map->getObjectgroupByName(S_InteractiveObjectGroupName);
	for (auto obj : group->getObjects() )
	{
		const SProperty* playerProp = obj->getPropertys()->getPropertyByName("player");
		if (playerProp)
		{
			const SProperty* animProp = obj->getPropertys()->getPropertyByName("anim");
			if (animProp)
			{
				int x = std::atoi( obj->getAttributes().at("x").c_str() );
				int y = std::atoi(obj->getAttributes().at("y").c_str());
				int id = std::atoi(obj->getAttributes().at("id").c_str());
				SDL_Rect rect;
				rect.x = x;
				rect.y = y;
				rect.w = 32;
				rect.h = 32;
				r_player = new Player(animProp->value.c_str(), rect, renderer);
			}
		}
	}
	return r_player;
}
