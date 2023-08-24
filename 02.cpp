#include <stdio.h>
#include <SDL2/SDL.h>

//function declarations
bool init();
bool loadMedia();
void close();

//global variables
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;


bool init() {
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		

	if(gWindow == NULL) {
		printf("Window could not be created! SDL_ERROR: %s\n",  SDL_GetError());
	}

	gScreenSurface = SDL_GetWindowSurface(gWindow);
}

	
	return success;
}

bool loadMedia() {
	bool success = true;

	gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
	if(gHelloWorld == NULL) {
		printf("Unable to load iamage %s! SDL ERROR: %s\n", "02_getting_an_image_on_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close() {
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}


int main(int argc, char* args[]) {
	if(!init()) {
		printf("Failed to initialize!\n");
	}

	//else
	if(!loadMedia()) {
		printf("Failed to load media!\n");
	}

	//else
	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

	SDL_UpdateWindowSurface(gWindow);

	SDL_Event e;
	bool quit = false;
	while(quit == false) {
		while(SDL_PollEvent) {
			if(e.type == SDL_QUIT) {
				quit = true;

			}
		}
	}

	close();

	return 0;
}
