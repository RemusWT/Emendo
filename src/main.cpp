

/*
-Load up window settings from a file containing the settings.
-Multiple key keybinds. E.G alt+f4 (tho this one might already work because of the OS).
-Reading from a text file and storing the information (For now we can printf it to the console, we also going to need another library).
-Font rendering the text (We are going to need another library for this).
*/


#include "engine.h"



int main(void) {
    printf("--DEBUG--\n\n");
    if (SDL_Init(SDL_INIT_VIDEO) != -0) {
		printf("Error: SDL_Init failed to initialize.\n");
		return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Emendo",
					  SDL_WINDOWPOS_CENTERED,
					  SDL_WINDOWPOS_CENTERED,
					  1280, 720, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool run = true;

    SDL_Event ev;
    while (run){
		// Event Handling
		while (SDL_PollEvent(&ev)) {
			switch(ev.type) {
				case SDL_QUIT:
				run = false;
				break;
			}
		}
		// Update renderer
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    printf("Program was executed without any errors.\n");
    SDL_Quit();
    return 0;
}
