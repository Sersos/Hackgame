#include "UIObject.h"
#include "Mouse.h"

UIObject::UIObject(float x, float y,
				   float width, float height,
				   Color& defaultColor, Color& hoverColor)
{
	m_rect.x = x;
	m_rect.y = y;

	m_rect.w = width;
	m_rect.h = height;

	m_defaultColor = defaultColor;
	m_hoverColor = hoverColor;
	m_currentColor = m_defaultColor;
}

bool UIObject::IsMouseOnObject(Mouse* mouse)
{
	int mousePosition[2];
	mousePosition[0] = mouse->GetMousePositionX(); //x
	mousePosition[1] = mouse->GetMousePositionY(); //y
	 
	if (mousePosition[0] >= m_rect.x &&
		mousePosition[0] <= (m_rect.x + m_rect.w) &&
		mousePosition[1] >= m_rect.y &&
		mousePosition[1] <= (m_rect.y + m_rect.h))
	{
		return true;
	}
	
	return false;
}

void UIObject::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, m_currentColor.r,
						   m_currentColor.g, m_currentColor.b, m_currentColor.g);
	SDL_RenderFillRect(renderer, &m_rect);
}

void UIObject::SetColor(short type)
{
	if (type == 0)
	{
		m_currentColor = m_defaultColor;
	}
	else
	{
		m_currentColor = m_hoverColor;
	}
}

Color* UIObject::GetCurrentColor()
{
	return &m_currentColor;
}

Color* UIObject::GetDefaultColor()
{
	return &m_defaultColor;
}

Color* UIObject::GetHoverDefault()
{
	return &m_currentColor;
}