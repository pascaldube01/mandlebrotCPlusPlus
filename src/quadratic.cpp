#include "quadratic.h"


void mandlebrot_point::init(double real, double imaginary){
    z0.real(real);
    z0.imag(imaginary);
    zn.real(real);
    zn.imag(imaginary);
}


void mandlebrot_point::square_add(){
    zn = (zn*zn) +z0;
}

void mandlebrot_point::display(){
    std::cout << "zn : " << zn << "    z0" << z0 << std::endl;
}