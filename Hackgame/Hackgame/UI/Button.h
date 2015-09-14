#ifndef BUTTON_H
#define BUTTON_H

#include "UIObject.h"

namespace UI
{
	/*
		This class provide a user interface button. You can place the object on a position 
		of x and y, you can also define a width and height for the object
	*/
	class Button : public UIObject
	{
	public:
		Button(float x, float y,
			   float width, float height,
			   Color& defaultColor, Color& hoverColor);

		void Update(Mouse* mouse) override;

	private:

	};
}

#endif
