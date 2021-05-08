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
typedef struct{
    unsigned h,w;
    unsigned x,y;
    int State;
}ExitButton;
typedef struct {
  Window* window;
  Array* array;
  unsigned delay;//delay between sorting actions

  int done;
  ExitButton ProgramState;// running or exit state
  unsigned menuSize;
  unsigned SortChoose;
} Context;

