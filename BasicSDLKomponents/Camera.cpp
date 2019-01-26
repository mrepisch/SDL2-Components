#include "Camera.h"

Camera::Camera(int posX, int posY)
{
	m_pos_x = posX;
	m_pos_y = posY;
	m_speed_x = 0;
	m_speed_y = 0;
}

Camera::~Camera()
{
}

void Camera::moveLeft()
{
	m_pos_x -= m_speed_x;
}

void Camera::moveRight()
{
	m_pos_x += m_speed_x;
	
}

void Camera::moveUp()
{
	m_pos_y += m_speed_y;
}

void Camera::moveDown()
{
	m_pos_y -= m_speed_y;
}

void Camera::reset()
{
	m_pos_x = 0;
	m_pos_y = 0;
}

void Camera::setSpeed(int x, int y)
{
	m_speed_x = x;
	m_speed_y = y;
}

int Camera::getPos_x() const
{
	return m_pos_x;
}

int Camera::getPox_y() const
{
	return m_pos_y;
}
