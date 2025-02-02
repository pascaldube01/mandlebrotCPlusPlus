#include <iostream>
#include "debug.h"
#include "window.h"
#include <complex>
#include "quadratic.h"
#include "mandlebrot_image.h"
#include "zoom.h"
#include "unistd.h"
#include "user_input.h"

#define MAIN_WINDOW_TEST 0
#define TEST_COMPLEX 0
#define TEST_QUADRATIC 0

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

int main(){

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::clog << "error : can't init SDL" << std::endl
                << "SDL_Error: " << SDL_GetError() << std::endl;
        exit(0);
    }

 

    #if(MAIN_WINDOW_TEST)
        window main_window;
        main_window.init(800,600);
     
        std::cout << "should be blue to red vertical gradient" << std::endl;
        main_window.test_set_bg();
        getc(stdin);
     
        main_window.destroy();
        std::cout << "test ran without crashing" << std::endl;

    #elif(TEST_COMPLEX)
        std::complex<double> complex_test(1,2);
        std::cout << complex_test << std::endl;
        complex_test.real(1.00);
        complex_test.imag(0.95);
        std::cout << complex_test << std::endl;
        for(int i = 0; i < 10; i++){
            complex_test = complex_test * complex_test;
            std::cout << complex_test << std::endl;
        }
    #elif(TEST_QUADRATIC)
        mandlebrot_point test_point;
        test_point.init(-1.2, 0.2);
        test_point.display();
        for(int i = 0; i < 50; i++){
            test_point.square_add();
            test_point.display();
        }
        test_point.init(-1.2, 0.2);
        test_point.recurse_until_escape();
        std::cout <<  "\n\ndid " << test_point.number_of_iterations << " iterations with non null\n\n" << std::endl;

        test_point.init(0, 0);
        test_point.recurse_until_escape();
        std::cout <<  "\n\ndid " << test_point.number_of_iterations << " iterations with null\n\n" << std::endl;

    //code without tests
    #else
        //setting up main window
        window main_window; 
        main_window.init(WINDOW_WIDTH,WINDOW_HEIGHT);

        //setting image render limit to initial position
        zoom_level image_limits;
        image_limits.im_hi = INITIAL_IMAGINARY_UPPER;
        image_limits.im_low = INITIAL_IMAGINARY_LOWER;
        image_limits.rl_hi = INITIAL_REAL_UPPER_LIMIT;
        image_limits.rl_low = INITIAL_REAL_LOWER_LIMIT;
        image_limits.window_height = WINDOW_HEIGHT;
        image_limits.window_width = WINDOW_WIDTH;

        //prepping image for initial display
        mandlebrot_image image;
        image.pixel_data_set(WINDOW_HEIGHT, WINDOW_WIDTH, main_window.bg_surface->pixels);

        image.set_image_limits(image_limits);
        image.set_step_size();
        image.calculate_points_single_thread();
        image.render_greyscale();
        main_window.set_bg();
        main_window.update_window();

        int operation_to_run = 0;
        mouse_state mouse_st;

        while((operation_to_run = handle_event(&mouse_st)))
        {
            switch(operation_to_run){
                case USR_REDRAW:
                    std::cout << "USR_REDRAW" << std::endl;
                    main_window.set_bg();
                    main_window.update_window();
                    break;
                case USR_MWHEEL:
                    scrool_zoom(&image_limits, mouse_st);
                    //std::cout << "USR_MWHEEL : " << mouse_st.wheel_y << std::endl;
                    std::cout << "im " << image_limits.im_hi << " : " << image_limits.im_low << std::endl;
                    std::cout << "rl " << image_limits.rl_hi << " : " << image_limits.rl_low << std::endl;
                    image.set_image_limits(image_limits);
                    image.set_step_size();
                    image.calculate_points_single_thread();
                    image.render_greyscale();
                    main_window.set_bg();
                    main_window.update_window();
                    break;
            }
        }

        image.pixel_data_destroy();
        main_window.destroy();    
    #endif
    
    SDL_Quit();
    
    return 0;
}











/*TODO*/

/*
zoom in/out
    scroolwheel
    square select
    avoid recalculating everything every frame
    reset zoom
    drag to pan

make ui
    escape path
        line only
        line with data
    show some data 
        current/available compute mode
        current color algo
        current position


resizeable window (change window size in window, mandlebrot and zoom)
    maximise
    border grab

color
    different coloring algos from wikipedia

different compute mode
    multithreading
    GPU
    long mode (custom unbound complex datatype)
*/