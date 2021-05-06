//
// Created by Dan on 4/28/2021.

#include "SDL_events.h"
#include "SDL_timer.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_render.h>
#include "sorting.h"
#include "graphics.h"

void callBack(Context* context)
{
     SDL_RenderClear(context->window->renderer);
     draw(context->array,context);
     SDL_RenderPresent(context->window->renderer);
     SDL_Delay(50); /**/
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
        array->data[i] = rand() % array->size;
    }
    context.window = window;
    context.array = array;


    callBack(&context);
   
    mergeSort(array,callBack,&context);


    while(1){
     callBack(&context);
    }




    return 0;
}
