#include "UIObject.h"

UIObject::UIObject(float x, float y,
				   float width, float height,
				   SDL_Color* color)
{
	
}

void UIObject::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, NULL, NULL, NULL);
}