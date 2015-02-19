#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	SDL_Window* window = NULL;
	int running;
	SDL_Surface* screenSurface = NULL;
	SDL_Event event;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			running=1;
			 while(running){
				 while(SDL_PollEvent(&event)){
					if(event.type == SDL_QUIT){
						running=0;
					}
				}
			}
		}
	}
	SDL_DestroyWindow( window );

	SDL_Quit();

	return 0;
}