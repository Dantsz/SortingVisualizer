//
// Created by Dan on 4/28/2021.
//
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>

int main(int argc, char *argv[])
{

    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("SORTING",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       500, 500, 0);
    while (1);

    return 0;
}
