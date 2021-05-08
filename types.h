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
  unsigned delay;//delay between sorting actions

  int done;


  unsigned MenuBack;
  unsigned menuSize;
  unsigned SortChoose;
} Context;

