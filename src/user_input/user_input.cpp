#include "user_input.h"



static void update_mouse_state(mouse_state *mouse_st);



user_triggered_ops handle_event(mouse_state *mouse_st){
    
    SDL_Event event;

    /*stuck here until user cause an event*/
    SDL_WaitEventTimeout(&event, 1);
    update_mouse_state(mouse_st);

    switch(event.type){
        case SDL_QUIT:
            return  USR_QUIT;
        case SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_SHOWN)
                return USR_REDRAW;
            break;
        case SDL_MOUSEWHEEL:
            mouse_st->wheel_y = event.wheel.y;
            return USR_MWHEEL;
        default:
            return USR_NO_EVENT;
    }

    return USR_NO_EVENT;
}





void update_mouse_state(mouse_state *mouse_st){
SDL_GetMouseState(&(mouse_st->pos_x), &(mouse_st->pos_y));

}