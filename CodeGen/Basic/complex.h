#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <stdbool.h>

class Complex
{
    private:
        float real;
        float imag;
    
    public:
        /* Constructors */
        Complex();
        Complex(float a, float b);
        
        /* Set Functions */
        void set_real(float r);
        void set_imag(float i);
        
        /* Get Functions */
        float get_real() const;
        float get_imag() const;
        float get_norm() const;
        
        /* Operators */
        Complex operator+(Complex const& op);
        Complex operator-(Complex const& op);
        Complex operator*(Complex const& op);
        Complex operator/(Complex const& op);
        bool operator==(Complex const& op);
        bool operator!=(Complex const& op);
        Complex operator!();

        /* Displays */
        void show();
        std::string to_str();
};

#endif