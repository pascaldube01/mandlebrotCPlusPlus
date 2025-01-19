#include "quadratic.h"


void mandlebrot_point::init(double real, double imaginary){
    z0.real(real);
    z0.imag(imaginary);
    zn.real(real);
    zn.imag(imaginary);
    number_of_iterations = 0;
}


void mandlebrot_point::square_add(){
    zn = (zn*zn) +z0;
}

void mandlebrot_point::display(){
    std::cout << "zn : " << zn << "    z0" << z0 << std::endl;
}

void mandlebrot_point::recurse_until_escape(){

    while(1)
    {

        /*check for escape condition*/
        if( zn.real() > ESCAPE_REAL_UPPPER_LIMIT ||
            zn.real() < ESCAPE_REAL_LOWER_LIMIT  ||
            zn.imag() > ESCAPE_IMAGINARY_UPPER   ||
            zn.imag() < ESCAPE_IMAGINARY_LOWER   ||
            number_of_iterations >= MAX_ITERATION){return;}



        zn = (zn*zn) +z0;
        number_of_iterations++;
        
        #if(TEST_RECURSE_OUTPUT)
            std::cout << number_of_iterations << " : " << zn << std::endl;
        #endif
    }
}