#include "user_input.h"

bool handle_user_input(){
    
    /*waiting for user input*/
    SDL_Event user_event;

    /*stuck here until user cause an event*/
    SDL_WaitEventTimeout(&user_event, 1);

    switch(user_event.type){
        case SDL_QUIT:
            return 0;
            break;
    }

    
    

    return 1;
}