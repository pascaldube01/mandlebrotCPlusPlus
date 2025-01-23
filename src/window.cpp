#include "window.h"


void window::set_pixel(SDL_Surface *surface, int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_LockSurface(surface);

    Uint8 * const pixel_cible =  ((Uint8 *) surface->pixels// NOTE, dans la ram c'et BGR et pas RGB
                                                + y * surface->pitch
                                                + x * surface->format->BytesPerPixel);
    pixel_cible[0] = b;
    pixel_cible[1] = g;
    pixel_cible[2] = r;

     SDL_UnlockSurface(surface);
}






void window::init(int image_width, int image_height){

    //creating window
    window = SDL_CreateWindow("Mandlebrot",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        image_width, image_height,
                                        SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        std::clog << "error : can't create window" << std::endl
                << "SDL_Error: " << SDL_GetError() << std::endl;
        exit(0);
    }

    /*getting window surface*/
    bg_surface = SDL_GetWindowSurface(window);
    if(bg_surface == NULL){
        std::clog << "error : can't get window surface" << std::endl
                << "SDL_Error: " << SDL_GetError() << std::endl;
    }


    /*putting black background*/
    SDL_SetSurfaceRLE(bg_surface, 1);

    for(int ligne = 0; ligne < bg_surface->h; ligne++)
        for(int colonne = 0; colonne < bg_surface->w; colonne++)
            set_pixel(bg_surface, colonne, ligne, 0, 0, 0);
}




void window::set_bg(void* new_pixels){

    int surface_size = (bg_surface->w * bg_surface->h * bg_surface->format->BytesPerPixel);

    SDL_LockSurface(bg_surface);
    memcpy(bg_surface->pixels, new_pixels, surface_size);
    SDL_UnlockSurface(bg_surface);
}




void window::update_window(){
    SDL_UpdateWindowSurface(window);
}


void window::destroy(){
    SDL_DestroyWindow(window);
}






/*tests*/






void window::test_set_pixel(){

    float gradient_increase_rate = ((float) 255 / (float) bg_surface->h);
    float current_gradient = 0;

    for(int i = 0; i < bg_surface->h; i++){
        int int_grad = (int) current_gradient;

        for(int j = 0; j < bg_surface->w; j++)
            set_pixel(bg_surface,j, i, int_grad, 0, 255 -int_grad);

        current_gradient += gradient_increase_rate;
    }
    update_window();
}





void window::test_set_bg(){
    int surface_size = (bg_surface->w * bg_surface->h * bg_surface->format->BytesPerPixel);
    
    std::vector<char> new_pixels(surface_size, 255);

    set_bg(new_pixels.data());

    update_window();
}
