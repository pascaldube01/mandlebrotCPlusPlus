#include <iostream>
#include "debug.h"
#include "window.h"
#include <complex>
#include "quadratic.h"
#include "mandlebrot_image.h"

#define MAIN_WINDOW_TEST 0
#define TEST_COMPLEX 0
#define TEST_QUADRATIC 0

#define WINDOW_WIDTH 800 
#define WINDOW_HEIGHT 600

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

        std::cout << "should be blue-red gradiant" << std::endl;
        main_window.test_set_pixel();
        getc(stdin);
     
        std::cout << "should be white screen" << std::endl;
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

        //prepping image for display
        mandlebrot_image image;
        image.pixel_data_create(WINDOW_HEIGHT, WINDOW_WIDTH);
        image.set_image_limits(INITIAL_IMAGINARY_UPPER, INITIAL_IMAGINARY_LOWER, INITIAL_REAL_UPPER_LIMIT, INITIAL_REAL_LOWER_LIMIT);

        image.set_step_size();

        image.fill_points_vector();

        image.pixel_data_destroy();
        main_window.destroy();    
    #endif
    
    SDL_Quit();
    
    return 0;
}