#include "render.h"

int init_renderer(SDL_Renderer **renderer, SDL_Window *window)
{
    *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL)
    {
        return -1;
    }
    return 0;
}

SDL_Texture *loadTexture(char *filename, SDL_Renderer **renderer)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(filename);
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(*renderer, loadedSurface);
        if (texture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", filename, SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return texture;
}

int loadMedia(char *filename, SDL_Texture **texture, SDL_Renderer **renderer)
{
    return (*texture = loadTexture(filename, renderer)) == NULL ? -1 : 0;
}

void render(SDL_Renderer *renderer, SDL_Rect *rect, SDL_Color *color)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
}

void texturedRender(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *rect)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, rect);
    SDL_RenderPresent(renderer);
}

void set_color(enum color colour, SDL_Color *color)
{
    switch (colour)
    {
    case RED:
        color->r = 255;
        color->g = 0;
        color->b = 0;
        color->a = 255;
        break;
    case GREEN:
        color->r = 0;
        color->g = 255;
        color->b = 0;
        color->a = 255;
        break;
    case BLUE:
        color->r = 0;
        color->g = 0;
        color->b = 255;
        color->a = 255;
        break;
    case WHITE:
        color->r = 255;
        color->g = 255;
        color->b = 255;
        color->a = 255;
        break;
    case YELLOW:
        color->r = 255;
        color->g = 255;
        color->b = 0;
        color->a = 255;
        break;
    default:
        break;
    }
}