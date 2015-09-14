#include "UIObject.h"

UIObject::UIObject(float x, float y,
				   float width, float height,
				   short r,
				   short g,
				   short b,
				   short a )
{
	m_rect.x = x;
	m_rect.y = y;

	m_rect.w = width;
	m_rect.h = height;

	m_color[0] = r;
	m_color[1] = g;
	m_color[2] = b;
	m_color[3] = a;
}

void UIObject::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer,
		m_color[0],
		m_color[1],
		m_color[2],
		m_color[3]);
	SDL_RenderFillRect(renderer, &m_rect);
}