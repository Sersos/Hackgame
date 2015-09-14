#include "Button.h"
#include <iostream>

UI::Button::Button(float x, float y,
	float width, float height,
	Color& defaultColor, Color& hoverColor)
	 : UIObject(x, y, width, height, defaultColor, hoverColor)
				  
{
	
}

void UI::Button::Update(Mouse* mouse)
{
	if (IsMouseOnObject(mouse))
	{
		std::cout << "hover" << std::endl;
		SetColor(1);
	}
	else
	{
		SetColor(0);
	}
}