#include <iostream>
#include "debug.h"
#include "window.h"

int main(){

    window main_window;

    main_window.init_window(800,600);
    main_window.test_set_pixel();

    return 0;
}