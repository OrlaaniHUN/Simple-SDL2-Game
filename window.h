#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int init_window(SDL_Window **window);
void window_destroy(SDL_Window *window, SDL_Surface *surface, SDL_Renderer *renderer, SDL_Texture *texture);

#endif // WINDOW_H