#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SDL.h>
#include <iostream>


typedef struct mouse_state{
    int pos_x;
    int pos_y;
    int wheel_y;
} mouse_state;


/*each value is 1 bit so they can be ored together as a return value*/
typedef enum {
    USR_QUIT = 0,
    USR_NO_EVENT = 1,
    USR_REDRAW = 2,
    USR_MWHEEL = 4
} user_triggered_ops;


/*check for SDL_events triggered by the user*/
user_triggered_ops handle_event(mouse_state *mouse_st);


#endif