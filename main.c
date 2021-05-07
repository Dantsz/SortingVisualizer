//
// Created by Dan on 4/28/2021.

#include "SDL_events.h"
#include "SDL_timer.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "sorting.h"
#include "graphics.h"

void callBack(Context* context)
{
     SDL_RenderClear(context->window->renderer);
     if(context->MenuBack == 0)
        draw(context->array,context);
     else
         drawMenu(context);
     SDL_RenderPresent(context->window->renderer);
     SDL_Delay(50); /**/
}
void rearrangeVect(Array *array) {
    for(unsigned  i = 0 ; i < array->size;i++)
    {
        array->data[i] = rand() % array->size;
        //printf("%u ",array->data[i]);
    }
}
void SortSelect(Array *array,void(*callBack)(Context*), Context *context) {
    //callBack(context);
    if(context->MenuBack == 1){
        printf("Actual SortChoose %u \n",context->SortChoose);
        switch (context->SortChoose) {
            case 0:
                rearrangeVect(array);
                context->done = 0;
                //SDL_Delay(500);
                selectionSort(array, callBack, context);//Probleme la slectionSort : Se face prea rapid si nu apucam sa vedem inceputul
                                                        // Si pare mereu ca e deja jumatate sortat.
                                                        //Nici chestia asta nu stiu cum sa o rezolv, cu delay sau sleep nu merge
                break;
            case 1:
                rearrangeVect(array);
                context->done = 0;
                //SDL_Delay(500);
                insertionSort(array, callBack, context);

                break;
            case 2:
                rearrangeVect(array);
                context->done = 0;
                //SDL_Delay(500);
                quickSort(array, callBack, context);
                break;
            case 3:
                rearrangeVect(array);
                context->done = 0;
                //SDL_Delay(500);
                mergeSort(array, callBack, context);
            case 4:
                //callBack(context);
                break;
            default:
                rearrangeVect(array);
                printf("Functiile nu sunt implementate inca!");
                break;
        }
    }

    callBack(context);
}

/*void Menu(Context* context)
{
    SDL_RenderClear(context->window->renderer);
    drawMenu(context);
    SDL_RenderPresent(context->window->renderer);
    SDL_Delay(50); /*
    */


int main(int argc, char *argv[])
{

    Context context;
    Window* window = createWindow(500,500,"Sorting");

    Array*  menuArr = malloc(sizeof(Array));
    menuArr->size = 5;
    menuArr->data = malloc(menuArr->size*sizeof(unsigned));


    Array*  array = malloc(sizeof(Array));
    array->size = 50;
    array->data = malloc(array->size*sizeof(unsigned));
    for(unsigned  i = 0 ; i < array->size;i++)
    {
        array->data[i] = rand() % array->size;
        //printf("%u ",array->data[i]);
    }
    context.window = window;
    context.array = array;
    context.done = 0;
    context.MenuBack = 1;
    context.menuSize = 4;
    context.SortChoose = 0;
   // callBack(&context);
   // selectionSort(array,callBack,&context);



    while(1){
       SortSelect(array,callBack,&context);
    }



    return 0;
}
