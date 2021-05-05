//
// Created by Dan on 4/28/2021.

#include "SDL_events.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_render.h>
#include "sorting.h"
#include "graphics.h"

void callBack(Context* context)
{

}

int main(int argc, char *argv[])
{

    Context context;
    Window* window = createWindow(500,500,"Sorting");
    Array*  array = malloc(sizeof(Array));
    array->size = 10;
    array->data = malloc(array->size*sizeof(unsigned));
    for(unsigned  i = 0 ; i < array->size;i++)
    {
        array->data[i] = i;
    }
    context.window = window;
    while(1){
     SDL_RenderClear(window->renderer);
     
     draw(array,&context);
   
     SDL_RenderPresent(window->renderer); 
    
    }




    return 0;
}
