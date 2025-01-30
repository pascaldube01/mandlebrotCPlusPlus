#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <vector>

class window{
    public:
        SDL_Window * window;

        SDL_Renderer *window_renderer;

        SDL_Surface * bg_surface; //background (calculated pixels) surface 
        SDL_Texture *bg_texture; //background GPU texture (created from bg_surface)



    /*event functions*/


    



    /*display functions*/



    void init(int image_width, int image_height);
    void destroy();


    
    //send new pixel data in BGRA format to background surface
    void set_bg();

    /*wrapper for SDL_UpdateWindowSurface*/
    void update_window();


    /*tests*/


    /*produces a gradient on screen*/
    void test_set_bg();

};

#endif