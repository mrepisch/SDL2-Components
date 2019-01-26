#pragma once
#include "Export.h"


class BASIC_KOMPONENT_API Camera
{
public:
	Camera(int posX = 0, int posY = 0);
	~Camera();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void reset();
	void setSpeed(int x, int y);
	int getPos_x() const;
	int getPox_y() const;

private:

	int m_pos_x = 0;
	int m_pos_y = 0;
	int m_speed_x = 0;
	int m_speed_y = 0;
};

