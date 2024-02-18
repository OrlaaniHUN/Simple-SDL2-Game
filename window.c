#include "window.h"

int init_window(SDL_Window **window)
{
    *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (*window == NULL)
    {
        SDL_DestroyWindow(*window);
        return -1;
    }

    return 0;
}

void window_destroy(SDL_Window *window, SDL_Surface *surface, SDL_Renderer *renderer, SDL_Texture *texture)
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
}