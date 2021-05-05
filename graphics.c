#include "graphics.h"



#include <SDL.h>
#include <SDL_render.h>
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
    window->width = width;
    window->height = height;
    return window;

}
void draw(Array* array,Context* context){

    unsigned rectWidth = context->window->width/array->size;// width of an box
    for(int i = 1 ; i <= array->size ; i ++)
    {
        int index = i -1;
        SDL_FRect rect;
        rect.w = rectWidth;
        rect.x = rectWidth * index;
        rect.y = context->window->height - (rectWidth*i);
        rect.h = rectWidth*i;
        SDL_SetRenderDrawColor(context->window->renderer, 255, 255, 255, 255);
        SDL_RenderFillRectF(context->window->renderer,&rect);
        SDL_SetRenderDrawColor(context->window->renderer, 100, 100, 100, 255);
        SDL_RenderDrawRectF(context->window->renderer,&rect);
        SDL_SetRenderDrawColor(context->window->renderer, 0, 0, 0, 255);
    }

}


