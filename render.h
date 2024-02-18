#ifndef RENDER_H
#define RENDER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum color
{
    RED = 0,
    GREEN,
    BLUE,
    WHITE,
    YELLOW
};

int init_renderer(SDL_Renderer **renderer, SDL_Window *window);
int loadMedia(char *filename, SDL_Texture **texture, SDL_Renderer **renderer);
SDL_Texture *loadTexture(char *filename, SDL_Renderer **renderer);
void render(SDL_Renderer *renderer, SDL_Rect *rect, SDL_Color *color);
void texturedRender(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *rect);
void set_color(enum color colour, SDL_Color *color);

#endif // RENDER_H