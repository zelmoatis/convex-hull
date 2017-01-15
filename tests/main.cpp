#include <iostream>
#include <SDL2/SDL.h>

// Screen dimension constants

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char const *argv[] ) {

	SDL_Window *window;

    SDL_Init( SDL_INIT_VIDEO );            

    
    window = SDL_CreateWindow(
        "curat",                  
        100,                 // Initial x position
        100,                 // Initial y position
        SCREEN_WIDTH,        // Width, in pixels
        SCREEN_HEIGHT,       // Height, in pixels
        SDL_WINDOW_OPENGL    
    );

    
    if ( window == NULL ) {
        printf( "Could not create window: %s\n", SDL_GetError() );
        return 0;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay( 3000 );  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window

    SDL_DestroyWindow( window );

    // Clean up

    SDL_Quit();

	return 0;
}