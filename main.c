//
// Created by Dan on 4/28/2021.


#include <stdio.h>
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "sorting.h"
#include "graphics.h"
#include "menu.h"
#include <stdlib.h>
void callBack(Context* context)
{
     SDL_RenderClear(context->window->renderer);
     draw(context->array,context);
     SDL_RenderPresent(context->window->renderer);
     SDL_Delay(context->delay); /**/
}
void rearrangeVect(Array *array) {
    for(unsigned  i = 0 ; i < array->size;i++)
    {
        array->data[i] = rand() % array->size;
        //printf("%u ",array->data[i]);
    }
}
void SortSelect(Array *array,void(*callBack)(Context*), Context *context) {
        printf("Actual SortChoose %u \n",context->SortChoose);
        sortFunction sorting[] ={selectionSort,insertionSort,quickSort,mergeSort};
        rearrangeVect(array);
        context->done = 0;
        sorting[context->SortChoose](array,callBack,context);

/*
        switch (context->SortChoose) {
            case 0:
                rearrangeVect(array);
                context->done = 0;
                selectionSort(array, callBack, context);
                break;
            case 1:
                rearrangeVect(array);
                context->done = 0;
                insertionSort(array, callBack, context);

                break;
            case 2:
                rearrangeVect(array);
                context->done = 0;
                quickSort(array, callBack, context);
                break;
            case 3:
                rearrangeVect(array);
                context->done = 0;
                mergeSort(array, callBack, context);
                break;
            case 4:
                 context->done = 0;
                break;
            default:
                context->done = 0;
                rearrangeVect(array);
                printf("Functiile nu sunt implementate inca!");
                break;
        
    }
*/
    callBack(context); //este necesar pt back
}


int main(int argc, char *argv[])
{

    Context context;
    context.delay = 50;
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
    }
    context.window = window;
    context.array = array;
    context.done = 0;
    context.ProgramState = 1;//
    context.menuSize = 4;
    context.SortChoose = 0;
   // callBack(&context);
   // selectionSort(array,callBack,&context);

    int btnDone = 0;
     
    while(context.ProgramState!=0){
      // SortSelect(array,callBack,&context);
      int sortType = drawMenu(&context);
      if(sortType != -1)
      {
          SortSelect(array,callBack,&context);
         do{
          SDL_RenderClear(context.window->renderer);
          draw(array,&context);
          btnDone = drawBackButton(&context);
          SDL_RenderPresent(context.window->renderer);
         }while(btnDone == 0);
        
         

      }
      
    }



    return 0;
}
