#ifndef MANDLEBROT_IMAGE_H
#define MANDLEBROT_IMAGE_H


#include "quadratic.h"
#include <vector>
#include <fstream>
#include <limits.h>
#include <format>
#include <cmath>

#define INITIAL_REAL_UPPER_LIMIT 1
#define INITIAL_REAL_LOWER_LIMIT -2
#define INITIAL_IMAGINARY_UPPER 1
#define INITIAL_IMAGINARY_LOWER -1

#define PPM_IMAGE_DEBUG_OUTPUT 0
#define EXPOSURE_SCALE_DEBUG_OUTPUT 0

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

    /*current limits of the set (zoom level)*/
    double real_lower_limit;
    double real_upper_limit;
    double imaginary_lower_limit;
    double imaginary_upper_limit;

    /*pixels on screen have a range of 0-255, the calculated set does not necessarely have that exact range so we use those values to rescale the min and
    max number of iterations to a 0-255 range making the image render properly*/
    int min_number_of_iterations;
    int max_number_of_iterations;

    //memory allocation of pixel array replacing the one in the buffer, use set_bg() in wincou.cpp to blit to window surface
    void pixel_data_create(int required_height, int required_width);

    //set the desired points limit for calculation (basicaly zoom level)
    void set_image_limits(double im_hi, double im_lo, double rl_hi, double rl_lo);

    //set pixel step size for each pixel between the range limit
    void set_step_size();

    //calculate all points escape for an image
    void calculate_points_single_thread();

    /*scale and render the calculated points on a greyscale image (in pixel_data)*/
    void render_greyscale();


    void pixel_data_destroy();



    //for testing

    void display_limit();
    void display_step_size();
};


#endif