#include "graphics.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

Window* createWindow(unsigned width,unsigned height,const char* name)
{
     if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    Window* window = malloc(sizeof(Window));
    window->sdlWindow = SDL_CreateWindow(name,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_RESIZABLE);
    window->renderer = SDL_CreateRenderer(window->sdlWindow, 0, 0);
    return window;

}


