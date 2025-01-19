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

//calculate an image
void mandlebrot_image::fill_points_vector(){


    #if(PPM_IMAGE_DEBUG_OUTPUT)
    #endif

    #if(PPM_IMAGE_DEBUG_OUTPUT)
    std::ofstream ppm_debug_image("image.ppm");
    ppm_debug_image << "P2\n" << image_width << " " << image_height << "\n" << MAX_ITERATION << "\n";
    #endif

    
    double cur_im = imaginary_lower_limit;

    //for every row of pixel
    for(int im_px = 0; im_px < image_height; im_px++)
    {
        //updating number to compute
        cur_im += imaginary_step_size;
        //std::cout << im_px << std::endl;

        //for every pixel in row
        double cur_rl = real_lower_limit;
        for(int rl_px = 0; rl_px < image_width; rl_px++)
        {
            cur_rl += real_step_size;
            //std::cout << "\t" << rl_px << std::endl;
            //create new point
            mandlebrot_point new_point;
            //set up witn cur_rl ad cur_im
            new_point.init(cur_rl, cur_im);
            //quad recurse until escape
            new_point.recurse_until_escape();
            //add to vector 
            calculated_points.push_back(new_point);
            ppm_debug_image << new_point.number_of_iterations << "\n";
        }
    }


    #if(PPM_IMAGE_DEBUG_OUTPUT)
    ppm_debug_image.close();
    #endif
}

