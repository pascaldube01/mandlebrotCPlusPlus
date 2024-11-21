#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <vector>

class window{
    public:
        SDL_Window * window;
        SDL_Surface * bg_surface;



    /*event functions*/


    



    /*display functions*/



    void init(int image_width, int image_height);
    void destroy();


    
    //send new pixel data in BGRA format to background surface
    void set_bg(void* new_pixels);
    //set a single pixel on a surface
    void set_pixel(SDL_Surface *surface, int x, int y, Uint8 r, Uint8 g, Uint8 b);

    /*wrapper for SDL_UpdateWindowSurface*/
    void update_window();


    /*tests*/

    /*displays a red to blue gradient*/
    void test_set_pixel();
    /*produces a white screen*/
    void test_set_bg();

};

#endif