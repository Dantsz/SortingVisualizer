#pragma once
#include <SDL_render.h>
typedef struct{
    SDL_Window* sdlWindow;
    SDL_Renderer* renderer;
    unsigned width,height;
    const char* name;
}Window;
typedef struct{
  unsigned* data;
  unsigned size;

}Array;

typedef struct {
  Window* window;
  Array* array;
  int done;
} Context;

