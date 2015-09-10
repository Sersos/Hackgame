#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;	
	
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

				SDL_Window* secondWindow = NULL;

				window = SDL_CreateWindow(
					"Window 2",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					500,
					500,
					SDL_WINDOW_OPENGL);

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
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}