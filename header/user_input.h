#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SDL.h>
#include <iostream>


typedef enum {
    USR_QUIT = 0,
    USR_NO_EVENT = 1,
    USR_REDRAW
} user_triggered_ops;


/*check for SDL_events triggered by the user*/
user_triggered_ops handle_event();


#endif