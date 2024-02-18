#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

void handle_events(int *quit, int *posX, int *posY, SDL_Color *color);

#endif // EVENT_HANDLER_H