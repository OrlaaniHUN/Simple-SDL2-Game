#include "event_handler.h"
#include "render.h"
#include <SDL2/SDL_events.h>

int colour = 0;
void handle_events(int *quit, int *posX, int *posY, SDL_Color *color)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            *quit = 1;
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(posX, posY);
            printf("Mouse moved\n, pos: %d, %d\n", *posX, *posY);
            break;
        case SDL_MOUSEBUTTONDOWN:
            printf("Mouse button down\n");
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                printf("Left mouse button down\n");
                colour--;
                if (colour < 0)
                {
                    colour = 4;
                }
                set_color(colour, color);
            }
            else if (event.button.button == SDL_BUTTON_RIGHT)
            {
                printf("Right mouse button down\n");
                colour++;
                if (colour > 4)
                {
                    colour = 0;
                }
                set_color(colour, color);
            }
            break;
        case SDL_WINDOWEVENT:
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_LEAVE:
                printf("Window lost focus\n");
                *posX = 800 / 2;
                *posY = 600 / 2;
                break;
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}
