#include "zoom.h"

void scrool_zoom(zoom_level *image_limits, mouse_state mouse_st){

double y_ratio = mouse_st.pos_y / (double) image_limits->window_height;
double x_ratio = mouse_st.pos_x / (double) image_limits->window_width;

std::cout << "y_ratio : " << y_ratio << mouse_st.pos_y << " // " << image_limits->window_height <<std::endl;
std::cout << "x_ratio : " << x_ratio << mouse_st.pos_x << " // " << image_limits->window_width <<std::endl;

image_limits->im_low += mouse_st.wheel_y*(ZOOM_FACTOR*(y_ratio));
image_limits->im_hi -= mouse_st.wheel_y*(ZOOM_FACTOR*(1-y_ratio));

image_limits->rl_low += mouse_st.wheel_y*(ZOOM_FACTOR*(x_ratio));
image_limits->rl_hi -= mouse_st.wheel_y*(ZOOM_FACTOR*(1-x_ratio));

}