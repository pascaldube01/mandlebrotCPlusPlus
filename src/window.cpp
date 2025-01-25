#include "window.h"









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

    /*creating background surface surface*/
    bg_surface = SDL_CreateRGBSurface(0,image_width,image_height,32,0,0,0,0);
    if(bg_surface == NULL){
        std::clog << "error : can't create background surface" << std::endl
                << "SDL_Error: " << SDL_GetError() << std::endl;
    }


    /*getting window hardware accelerated renderer*/
    window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    /*putting black background*/
    SDL_RenderDrawRect(window_renderer, NULL);
    SDL_RenderPresent(window_renderer);
}




void window::set_bg(void* new_pixels){

    int surface_size = (bg_surface->w * bg_surface->h * bg_surface->format->BytesPerPixel);

    SDL_LockSurface(bg_surface);
    memcpy(bg_surface->pixels, new_pixels, surface_size);
    SDL_UnlockSurface(bg_surface);

    SDL_Texture *bg_texture = SDL_CreateTextureFromSurface(window_renderer, bg_surface);

    SDL_RenderCopy(window_renderer, bg_texture, NULL, NULL);

    SDL_DestroyTexture(bg_texture);
}




void window::update_window(){
    SDL_RenderPresent(window_renderer);
}


void window::destroy(){
    SDL_DestroyWindow(window);
}






/*tests*/




void window::test_set_bg(){
    int surface_size = (bg_surface->w * bg_surface->h * 4);
    
    std::vector<char> new_pixels(surface_size, 255);

    float gradient_increase_rate = ((float) 255 / (float) bg_surface->h);
    float current_gradient = 0;

    for(int i = 0; i < bg_surface->h; i++){
        int int_grad = (int) current_gradient;

        for(int j = 0; j < bg_surface->w; j++){
            int current_pos = ((bg_surface->w * i*4)+j*4);
            new_pixels[current_pos] = int_grad;
            new_pixels[current_pos+1] = 0;
            new_pixels[current_pos+2] = 255 - int_grad;
            new_pixels[current_pos+3] = 255;
        }

        current_gradient += gradient_increase_rate;
    }


    set_bg(new_pixels.data());

    update_window();
}
