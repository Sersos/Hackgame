#ifndef UIOBJECT_H
#define UIOBJECT_H

#include <SDL.h>

/*
	Base class for all user interface objects
*/

class UIObject 
{
public:
	UIObject(float x, float y,
		float width, float height,
		short r,
		short g,
		short b,
		short a);

	void Render(SDL_Renderer* renderer);	

private:
	SDL_Rect m_rect;	
	short m_color[4];

};

#endif