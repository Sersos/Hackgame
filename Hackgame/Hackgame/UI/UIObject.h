#ifndef UIOBJECT_H
#define UIOBJECT_H

#include <SDL.h>

/*
	Base class for all user interface objects
*/

class Mouse;

struct Color
{
	short r, g, b, a;
};

enum ColorModes
{
	DEFAULT_COLOR,
	HOVER_COLOR,
};

class UIObject 
{
public:
	UIObject(float x, float y,
		float width, float height,
		Color& defaultColor, Color& hoverColor);

	bool IsMouseOnObject(Mouse* mouse);

	virtual void Update(Mouse* mouse) = 0;

	void Render(SDL_Renderer* renderer);	

	void SetColor(short type);

	inline Color* GetCurrentColor();
	inline Color* GetDefaultColor();
	inline Color* GetHoverDefault();

private:
	SDL_Rect m_rect;	
	
	Color m_defaultColor;
	Color m_hoverColor;
	Color m_currentColor;

};

#endif