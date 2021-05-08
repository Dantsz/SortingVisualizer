#include "graphics.h"
//#include <SDL_ttf.h>

#include <SDL.h>
#include <SDL_render.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Window* createWindow(unsigned width,unsigned height,const char* name)
{
     if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    Window* window = malloc(sizeof(Window));
    window->sdlWindow = SDL_CreateWindow(name,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_RESIZABLE);
    window->renderer = SDL_CreateRenderer(window->sdlWindow, 0, 0);
    window->width = width;
    window->height = height;
    return window;

}
int mouse(Context *context, unsigned ButtonWidth, unsigned ButtonHeight)
{
    SDL_Event mouse;
    while (SDL_PollEvent(&mouse))
    {
        if(mouse.button.clicks == 1)
            if(mouse.button.x <= 10 + ButtonWidth && mouse.button.x > 10 && mouse.button.y <= 10 + ButtonHeight && mouse.button.y > 10)
            {
               return 1;
            }
    }
    return 0;
}
int drawBackButton(Context *context){


/*
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //this opens a font style and sets a size

    SDL_Color White = {255, 255, 255,255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

    SDL_Texture* Message = SDL_CreateTextureFromSurface(context->window->renderer, surfaceMessage); //now you can convert it into a texture

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect

//Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understand

//Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

    SDL_RenderCopy(context->window->renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

//Don't forget to free your surface and texture


*/


    unsigned ButtonWidth = context->window->width / 8;
    unsigned ButtonHeight = context->window->height / 15;
    SDL_FRect button;
    button.h= ButtonHeight;
    button.w = ButtonWidth;
    button.x = 10;
    button.y = 10;
    SDL_SetRenderDrawColor(context->window->renderer, 0, 255, 0, 255);
    SDL_RenderFillRectF(context->window->renderer,&button);
    SDL_SetRenderDrawColor(context->window->renderer, 0, 0, 0, 255);
    return mouse(context,ButtonWidth,ButtonHeight);


}
static void drawMenuButtons(Context* context, int h,int w, int x,int y)
{
    SDL_FRect button;
    button.h = h;
    button.w = w;
    button.x = x;
    button.y = y;
    SDL_SetRenderDrawColor(context->window->renderer, 0, 255, 0, 255);
    SDL_RenderFillRectF(context->window->renderer,&button);
    SDL_SetRenderDrawColor(context->window->renderer, 0, 0, 0, 255);
}
int drawMenu(Context* context){
    SDL_RenderClear(context->window->renderer);
    SDL_FRect title;
    title.h = context->window->height/10;
    title.w = context->window->width/3;
    title.x = context->window->width/2 - title.w/2;
    title.y = context->window->height/5;
    SDL_SetRenderDrawColor(context->window->renderer, 0, 0, 100, 255);
    SDL_RenderFillRectF(context->window->renderer,&title);
    SDL_SetRenderDrawColor(context->window->renderer, 0, 0, 0, 255);
    int w = context->window->width/(2 * context->menuSize);
    int h = w - w/6;
    int distance = 2 * w;
    unsigned center = w/2;
    int y = context->window->height - context->window->height/4;
    int x;
    for(unsigned i = 0 ; i < context->menuSize ; i++)
    {
        x = distance * i + center;
        drawMenuButtons(context, h, w, x, y);

    }
  
    
   
    SDL_RenderPresent(context->window->renderer);
    return choices(context,distance);

}

void draw(Array* array,Context* context){

    unsigned rectWidth = context->window->width/array->size;// width of an box

    for(unsigned i = 1 ; i <= array->size ; i ++)
    {
        unsigned index = i -1;
        SDL_FRect rect;
        rect.w = rectWidth;
        rect.x = rectWidth * index ;
        rect.y = context->window->height - (rectWidth*(array->data[index]+1));
        rect.h = rectWidth*(array->data[index]+1);
        if(context->done == 1)
        {   

          SDL_SetRenderDrawColor(context->window->renderer, 0, 255, 0, 255);
          SDL_RenderFillRectF(context->window->renderer, &rect);
          SDL_SetRenderDrawColor(context->window->renderer, 0, 100, 0, 255);
              
        }
        else {
            SDL_SetRenderDrawColor(context->window->renderer, 255, 255, 255, 255);
            SDL_RenderFillRectF(context->window->renderer, &rect);
            SDL_SetRenderDrawColor(context->window->renderer, 100, 100, 100, 255);
        }
        SDL_RenderDrawRectF(context->window->renderer,&rect);
        SDL_SetRenderDrawColor(context->window->renderer, 0, 0, 0, 255);
    }

}

int choices(Context* context, unsigned distance)
{
    int w = context->window->width/(2 * context->menuSize);
    int h = w - w/6;
    int y = context->window->height - context->window->height/4;
    int center = distance / 4;
    SDL_Event mouse;
    while (SDL_PollEvent(&mouse))
    {
        if(mouse.button.clicks == 1)
        {
           for(unsigned i = 0; i < context->menuSize; i++)
           {
                if(mouse.button.x > (i * distance + center) && mouse.button.x < (i * distance + center + w) &&
                        mouse.button.y > y && mouse.button.y < (y + h))
                {
                    context->MenuBack = 0;
                    context->SortChoose = i;
                    //aici am probleme de timing pe care nu stiu cum sa le rezolv momentan
                    //ideea e ca atunci cand apesi pe un buton ca sa selectezi un anumit tip de sort avem nevoie sa trimitem optiunea prin
                    // alegem ce tip de sort vrem sa faca in acelasi timp in care trebuie sa marcam schimbarea meniului catre pagina de drawing
                    //Deci problema care apare e ca daca vrei sa alegi un anumit tip de sorting chiar daca il apesi pe ala o sa ti-l faca pe cel ales anterior
                    // si dupa ce il alegi a doua oara o sa il faca pe ala corect.
                    return i; 
                    
                }

            }



        }
    }
    return -1;
}


