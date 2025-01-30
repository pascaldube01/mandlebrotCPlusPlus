#include "user_input.h"

user_triggered_ops handle_event(){
    
    /*waiting for user input*/
    SDL_Event event;

    /*stuck here until user cause an event*/
    SDL_WaitEventTimeout(&event, 1);

    switch(event.type){
        case SDL_QUIT:
            return  USR_QUIT;
        case SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_SHOWN)
                return USR_REDRAW;
            break;
        default:
            return USR_NO_EVENT;
    }

    return USR_NO_EVENT;
}



/*

retval could be:
redraw
recolor
quit
recalculate full
recalculate part
*/