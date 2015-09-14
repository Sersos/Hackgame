#ifndef UIOBJECT_H
#define UIOBJECT_H

#include <SDL.h>

class UIObject 
{
public:
	UIObject(
		float x, float y,
		float width, float height,
		SDL_Color* color);

	void Render(SDL_Renderer* renderer);	

private:
	SDL_Rect* m_object;

};

#endif