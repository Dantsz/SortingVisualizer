#pragma once
#include "graphics.h"
//#include <SDL_ttf.h>

#include <SDL.h>
#include <SDL_render.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>

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

    for(unsigned i = 1 ; i <= array->size ; i ++)
    {
        unsigned index = i -1;
        SDL_FRect rect;
        rect.w = rectWidth;
        rect.x = rectWidth * index ;
        rect.y = context->window->height - (rectWidth*(array->data[index]+1));
        rect.h = rectWidth*(array->data[index]+1);
        if(context->done == 1)
        {   

          SDL_SetRenderDrawColor(context->window->renderer, 0, 255, 0, 255);
          SDL_RenderFillRectF(context->window->renderer, &rect);
          SDL_SetRenderDrawColor(context->window->renderer, 0, 100, 0, 255);
              
        }
        else {
            SDL_SetRenderDrawColor(context->window->renderer, 255, 255, 255, 255);
            SDL_RenderFillRectF(context->window->renderer, &rect);
            SDL_SetRenderDrawColor(context->window->renderer, 100, 100, 100, 255);
        }
        SDL_RenderDrawRectF(context->window->renderer,&rect);
        SDL_SetRenderDrawColor(context->window->renderer, 0, 0, 0, 255);
    }


}




