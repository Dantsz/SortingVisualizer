#pragma once
#include "SDL_render.h"
#include "SDL_video.h"
#include "sorting.h"
typedef struct{
    SDL_Window* window;
    SDL_Renderer* renderer;
    unsigned width,height;
    const char* name;
}Window;

void createWindow();
void draw(Array* array,Context* context);
void destroyWindow();

