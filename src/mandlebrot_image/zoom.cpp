#include "zoom.h"

void scrool_zoom(zoom_level *image_limits, mouse_state mouse_st){

double y_ratio = mouse_st.pos_y / (double) image_limits->window_height;
double x_ratio = mouse_st.pos_x / (double) image_limits->window_width;

double range_im = abs(image_limits->im_hi - image_limits->im_low);
double range_rl = abs(image_limits->rl_hi - image_limits->rl_low);

std::cout << "range im : " << range_im << std::endl;
std::cout << "range rl : " << range_rl << std::endl;


//std::cout << "y_ratio : " << y_ratio << mouse_st.pos_y << " // " << image_limits->window_height std::endl;
//std::cout << "x_ratio : " << x_ratio << mouse_st.pos_x << " // " << image_limits->window_width <<std::endl;

image_limits->im_low += mouse_st.wheel_y*(ZOOM_FACTOR*(y_ratio))*range_im;
image_limits->im_hi -= mouse_st.wheel_y*(ZOOM_FACTOR*(1-y_ratio))*range_im;

image_limits->rl_low += mouse_st.wheel_y*(ZOOM_FACTOR*(x_ratio))*range_rl;
image_limits->rl_hi -= mouse_st.wheel_y*(ZOOM_FACTOR*(1-x_ratio))*range_rl;

}