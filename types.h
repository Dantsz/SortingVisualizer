#pragma once
#include <SDL_render.h>
typedef struct{
    SDL_Window* sdlWindow;
    SDL_Renderer* renderer;
    unsigned width,height;
    const char* name;
}Window;


typedef struct {
  Window* window;
} Context;

typedef struct{
  unsigned* data;
  unsigned size;

}Array;