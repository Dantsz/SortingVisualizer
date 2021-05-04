//
// Created by Dan on 4/28/2021.

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

    Window* window = createWindow(500,500,"Sorting");
    while(1){
     SDL_RenderClear(window->renderer);

     SDL_RenderPresent(window->renderer); 
     SDL_Delay(500);  
    }




    return 0;
}
