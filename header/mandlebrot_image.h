#ifndef MANDLEBROT_IMAGE_H
#define MANDLEBROT_IMAGE_H


#include "quadratic.h"
#include <vector>
#include <fstream>

#define INITIAL_REAL_UPPER_LIMIT 1
#define INITIAL_REAL_LOWER_LIMIT -2
#define INITIAL_IMAGINARY_UPPER 1
#define INITIAL_IMAGINARY_LOWER -1

#define PPM_IMAGE_DEBUG_OUTPUT 0
#define EXPOSURE_SCALE_DEBUG_OUTPUT 1

class mandlebrot_image{
    public:
    //image stuff
    unsigned char * pixel_data; //in BGRA format
    int image_height;
    int image_width;

    //mandlebrot compute stuff
    //complex points to calculate untill escape
    std::vector <mandlebrot_point> calculated_points;
    double real_step_size;
    double imaginary_step_size;

    double real_lower_limit;
    double real_upper_limit;
    double imaginary_lower_limit;
    double imaginary_upper_limit;

    //memory allocation of pixel array replacing the one in the buffer, use set_bg()
    //all those function must be calld at creation in this order
    void pixel_data_create(int required_height, int required_width);
    void set_image_limits(double im_hi, double im_lo, double rl_hi, double rl_lo);
    void set_step_size();


    void calculate_points_single_thread();

    void render_greyscale();

    void pixel_data_destroy();



    //for testing

    void display_limit();
    void display_step_size();
};


#endif