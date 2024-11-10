#include <complex>
#include <iostream>

class mandlebrot_point{
public:

    /*quadratic recursion for mandlebrot set is zn+1=(zn^2)+z0*/

    std::complex<double> z0; //initial complex
    std::complex<double> zn; //
    int n;


    void init(double real, double imaginary);
    void square_add();
    void display();


};