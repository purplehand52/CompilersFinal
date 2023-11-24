#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <stdbool.h>
#include <string>
#include <sstream>

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
        Complex operator/(const int a);
        bool operator==(Complex const& op);
        bool operator!=(Complex const& op);
        Complex operator!();

        /* Displays */
        void show();
        std::string to_str();
        friend std::ostream &operator<<(std::ostream &os, Complex const &c);
        // template <typename T>
        // friend std::string to_string_with_precision(const T, const int n = 6);
};

#endif