#include "Mouse.h"
#include "SDL.h"
#include <iostream>

Mouse::Mouse()
{
	m_x = 0;
	m_y = 0;
}

void Mouse::Update()
{
	SDL_GetMouseState(&m_x, &m_y);
	std::cout << "X: " << m_x << std::endl;
	std::cout << "Y: " << m_y << std::endl;
}

int Mouse::GetMousePositionX()
{
	return m_x;
}

int Mouse::GetMousePositionY()
{
	return m_y;
}