#include "mandlebrot_image.h"

void mandlebrot_image::pixel_data_create(int required_height, int required_width){
    image_width = required_width;
    image_height = required_height;
    pixel_data = new char[image_width * image_height *4];
}


void mandlebrot_image::pixel_data_destroy(){
    delete[] pixel_data;
    image_width = 0;
    image_height = 0;
}


void mandlebrot_image::set_step_size(){
    double im_range = imaginary_upper_limit - imaginary_lower_limit;
    double real_range = real_upper_limit - real_lower_limit;

    real_step_size = real_range / image_width;
    imaginary_step_size = im_range / image_height;
}


void mandlebrot_image::set_image_limits(double im_hi, double im_lo, double rl_hi, double rl_lo){

    real_lower_limit = rl_lo;
    real_upper_limit = rl_hi;
    imaginary_lower_limit = im_lo;
    imaginary_upper_limit = im_hi;
}


void mandlebrot_image::fill_points_vector(){

    
}

