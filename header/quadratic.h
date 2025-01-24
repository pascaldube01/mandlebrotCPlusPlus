#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <complex>
#include <iostream>


#define TEST_RECURSE_OUTPUT 0



#define ESCAPE_REAL_UPPPER_LIMIT 100
#define ESCAPE_REAL_LOWER_LIMIT -100
#define ESCAPE_IMAGINARY_UPPER 100
#define ESCAPE_IMAGINARY_LOWER -100
#define MAX_ITERATION 350

class mandlebrot_point{
public:

    /*quadratic recursion for mandlebrot set is zn+1=(zn^2)+z0*/

    std::complex<double> z0; //initial complex
    std::complex<double> zn; // current complex
    int number_of_iterations;// n 


    void init(double real, double imaginary);
    
    void recurse_until_escape(); //square_add until an escape is reached (see #defines)


    //for tests
    void display();//used for testing
    void square_add(); //perform zn+1=(zn^2)+z0 (used for testing, call recurse_until_escape)

};

#endif