#include <stdio.h>
#include <SDL2/SDL.h>
#include "event_handler.h"
#include "window.h"
#include "render.h"

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;

#define OFFSET 50
int main(int argc, char *args[])
{
    int pngMode = 0;
    int quit = 0;
    int posX = 100;
    int posY = 100;
    SDL_Rect rect = {posX / 2, posY / 2, 100, 100};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        window_destroy(window, surface, renderer, texture);
        return -1;
    }

    if (init_window(&window) != 0)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        window_destroy(window, surface, renderer, texture);
        return -1;
    }

    if (init_renderer(&renderer, window) != 0)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        window_destroy(window, surface, renderer, texture);
        return -1;
    }

    if (argc > 1 && strcmp(args[1], "-f") == 0)
    {
        printf("Filename: %s\n", args[2]);
        if (loadMedia(args[2], &texture, &renderer) == 0)
        {
            pngMode = 1;
        }
    }

    surface = SDL_GetWindowSurface(window);
    SDL_Color color = {255, 0, 0, 255};
    // SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0, 0, 100));
    while (!quit)
    {
        handle_events(&quit, &posX, &posY, &color);
        rect.x = posX - OFFSET;
        rect.y = posY - OFFSET;
        // SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
        // SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0, 0, 100));
        // SDL_UpdateWindowSurface(window);
        if (pngMode == 1)
        {
            texturedRender(renderer, texture, &rect);
        }
        else
        {
            render(renderer, &rect, &color);
        }

        SDL_Delay(1000 / 60);
    }

    printf("Quitting application!\n");
    window_destroy(window, surface, renderer, texture);
    return 0;
}