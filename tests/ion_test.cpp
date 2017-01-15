#include <iostream>
#include <SDL2/SDL.h>

// Screen dimension constants

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char const *argv[] ) {

	SDL_Window     *window;
    SDL_Renderer   *renderer;
    SDL_Event      event;

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

    renderer = SDL_CreateRenderer( window, -1, 0 );

    while( true ) {

        SDL_WaitEvent( &event );
        if ( event.type == SDL_QUIT ) {
            break;
        }

        // Select the color for drawing. It is set to red here.
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

        // Clear the entire screen to our selected color.
        SDL_RenderClear( renderer );

        SDL_SetRenderDrawColor( renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        
        SDL_RenderDrawLine( renderer, 320, 200, 300, 240);

        // Up until now everything was drawn behind the scenes.
        // This will show the new, red contents of the window.
        SDL_RenderPresent( renderer );


        
    }  

    // Close and destroy the window

    SDL_DestroyWindow( window );

    // Clean up

    SDL_Quit();

	return 0;
}