#include <SDL.h>
#include <iostream>
#include "Button.h"
#include "Mouse.h"

int main( int argc, char* argv[] )
{
	SDL_Window* window = NULL;	
	SDL_Renderer* renderer = NULL;

	Mouse* mouse = new Mouse;	
			
	SDL_Init( SDL_INIT_EVERYTHING );

	window = SDL_CreateWindow(
		"Hackgame",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1280,
		720,
		SDL_WINDOW_OPENGL);

	if (window == NULL)	{
		std::cout << "Could not create Window" << SDL_GetError() << std::endl;
	}

	Uint32 windowId = SDL_GetWindowID(window);

	Color defaultColor;
	defaultColor.r = 255;
	defaultColor.g = 0;
	defaultColor.b = 0;
	defaultColor.a = 255;

	Color hoverColor;
	hoverColor.r = 0;
	hoverColor.g = 255;
	hoverColor.b = 0;
	hoverColor.a = 255;

	UI::Button button = UI::Button(50, 50, 250, 250, defaultColor, hoverColor);

	while (true)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			//receive window event
			case SDL_WINDOWEVENT:
			{
				//check if our window is in event
				if (event.window.windowID = windowId) {
					switch (event.window.event)
					{
						//if window close button pressed
						case SDL_WINDOWEVENT_CLOSE:
						{
							//change current event type to 'window closed' -> close window
							event.type = SDL_QUIT;
							SDL_PushEvent(&event);
							break;
						}
					}
				}
				break;
			}
			case SDL_MOUSEBUTTONUP:
			{
				std::cout << "Mouse clicked" << std::endl;				

				break;
			}
			//if event type is equal to 'SDL_QUIT' close program
			case SDL_QUIT:
			{
				
				
				return 0;
			}
			default:
				break;
			}
		}
		
		//update mouse stats
		mouse->Update();

		renderer = SDL_CreateRenderer(window, 0, 0);

		SDL_RenderClear(renderer);

		button.Update(mouse);
		button.Render(renderer);

		//display content
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}