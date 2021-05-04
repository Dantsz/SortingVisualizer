#pragma once
#include "SDL_render.h"
#include "SDL_video.h"
#include "sorting.h"
typedef struct{
    SDL_Window* sdlWindow;
    SDL_Renderer* renderer;
    unsigned width,height;
    const char* name;
}Window;

Window* createWindow(unsigned width,unsigned height,const char* name);
void draw(Array* array,Context* context);


void destroyWindow();

