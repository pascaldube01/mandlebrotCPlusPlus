#include "mandlebrot_image.h"


/*pixel_Data must have been created by window::init*/
void mandlebrot_image::pixel_data_set(int required_height, int required_width, void * new_pixel_data){
    image_width = required_width;
    image_height = required_height;
    pixel_data = (unsigned char *)new_pixel_data;
    calculated_points = new mandlebrot_point[image_width*image_height];
}


void mandlebrot_image::pixel_data_destroy(){
    delete[] calculated_points;
    pixel_data = NULL; //not being freeed because the window created it, il will be freed by window::destroy
    image_width = 0;
    image_height = 0;
}


void mandlebrot_image::set_step_size(){
    /*calculating the full range of imaginary and real parts*/
    double im_range = imaginary_upper_limit - imaginary_lower_limit;
    double real_range = real_upper_limit - real_lower_limit;

    /*calculating im and rl step per pixel based on window resolution*/
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
void mandlebrot_image::calculate_points_single_thread(){

    #if(PPM_IMAGE_DEBUG_OUTPUT)
    std::ofstream ppm_debug_image("image.ppm");
    ppm_debug_image << "P2\n" << image_width << " " << image_height << "\n" << MAX_ITERATION << "\n";
    #endif


    #if(EXPOSURE_SCALE_DEBUG_OUTPUT)
    int *intensity = new int[MAX_ITERATION+1];
    std::ofstream intensity_CSV_out("intensity.csv");
    #endif


    /*resetting the min and max values that will be used in the  color/value scaling algorithm*/
    min_number_of_iterations = INT_MAX;
    max_number_of_iterations = 0;

    
    double cur_im = imaginary_lower_limit;

    //for every row of pixel
    for(int im_px = 0; im_px < image_height; im_px++)
    {
        //updating number to compute
        cur_im += imaginary_step_size;

        //for every pixel in row
        double cur_rl = real_lower_limit;
        for(int rl_px = 0; rl_px < image_width; rl_px++)
        {
            cur_rl += real_step_size;

            mandlebrot_point *new_point = &calculated_points[(im_px*image_width) + rl_px];
            
            //set up point witn cur_rl ad cur_im
            new_point->init(cur_rl, cur_im);
            //quad recurse until escape
            new_point->recurse_until_escape();


            /*checing if the limit has changed*/
            if(new_point->number_of_iterations > max_number_of_iterations)
                max_number_of_iterations = new_point->number_of_iterations;
            else if(new_point->number_of_iterations < min_number_of_iterations)
                min_number_of_iterations = new_point->number_of_iterations;

            //these can be enabled in the .h
            #if(PPM_IMAGE_DEBUG_OUTPUT)
            ppm_debug_image << new_point->number_of_iterations << "\n";
            #endif

            #if(EXPOSURE_SCALE_DEBUG_OUTPUT)
            intensity[new_point->number_of_iterations]++;
            #endif
        }
    }


    //std::cout << "from " << min_number_of_iterations << " to " << max_number_of_iterations <<std::endl;

    #if(PPM_IMAGE_DEBUG_OUTPUT)
    ppm_debug_image.close();
    #endif
    #if(EXPOSURE_SCALE_DEBUG_OUTPUT)

    for(int i = 0; i < MAX_ITERATION; i++)
    intensity_CSV_out << intensity[i] << "\n";
    delete[] intensity;
    intensity_CSV_out.close();
    #endif
}



void mandlebrot_image::render_greyscale(){

    int range = (max_number_of_iterations - min_number_of_iterations);
    double scaling_factor = ((double) UCHAR_MAX )/ (double) range;

    std::cout << range << " , " << scaling_factor <<  std::endl;

    for(int pos = 0; pos < image_height*image_width; pos++){
        
        int current_position_pixel_data =pos*4;
        unsigned char pixel_value = (calculated_points[pos].number_of_iterations - min_number_of_iterations) * scaling_factor;
       
        pixel_data[current_position_pixel_data] = pixel_value;
        pixel_data[current_position_pixel_data+1] = pixel_value;
        pixel_data[current_position_pixel_data+2] = pixel_value;
        pixel_data[current_position_pixel_data+3] = 255;
    }
}