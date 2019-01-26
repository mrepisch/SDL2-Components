#include "pch.h"
#include "Player.h"


Player::Player(const char * xmlFile, SDL_Rect rect, SDL_Renderer* renderer) : SpriteAnimation(xmlFile,rect,renderer)
{
	m_hp = 100;
	m_mp = 100;
	m_int = 10;
}

Player::~Player()
{
}

void Player::update()
{
}
