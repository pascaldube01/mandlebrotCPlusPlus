#ifndef ZOOM_H
#define ZOOM_H

#include "user_input.h"
#include <iostream>


#define INITIAL_REAL_UPPER_LIMIT 1
#define INITIAL_REAL_LOWER_LIMIT -2
#define INITIAL_IMAGINARY_UPPER 1
#define INITIAL_IMAGINARY_LOWER -1

#define ZOOM_FACTOR 0.05


typedef struct zoom_level{
    double rl_low;
    double rl_hi;
    double im_low;
    double im_hi;

    //needed for zoom calculation
    int window_height;
    int window_width;
} zoom_level;


void scrool_zoom(zoom_level *image_limits, mouse_state mouse_st);


#endif