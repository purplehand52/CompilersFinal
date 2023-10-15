/* Only dealing with square matrices here! */
#ifndef MATRIX_H
#define MATRIX_H

#include "complex.h"
#include <stdbool.h>

class Matrix
{
    private:
        unsigned int n;
        Complex* arr;
    
    public:
        /* Constructions */
        Matrix(unsigned int n);

        /* Set Functions */
        void set_entry(unsigned int i, unsigned int j, Complex c);

        /* Get Functions */
        Complex get_entry(unsigned int i, unsigned int j) const;
        unsigned int get_dim() const;

        /* Operators */
        Matrix operator+(Matrix const& op);
        Matrix operator-(Matrix const& op);
        Matrix operator*(Matrix const& op);
        Matrix operator!();

        /* Misc */
        bool is_unitary() const;

        /* Displays */
        void show();
};

#endif