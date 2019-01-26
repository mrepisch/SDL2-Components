#pragma once
#include "SpriteAnimation.h"
#include "SDL.h"

class Player : public SpriteAnimation
{
public:
	Player(const char* xmlFile, SDL_Rect rect, SDL_Renderer* renderer);
	~Player();

	void update();

	

private:
	int m_hp;
	int m_mp;
	int m_int;
};

