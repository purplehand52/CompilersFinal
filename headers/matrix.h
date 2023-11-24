/* Only dealing with square matrices here! */
#ifndef MATRIX_H
#define MATRIX_H

#include "complex.h"
#include <stdbool.h>

class Matrix
{
    private:
        unsigned int n;
        Complex** arr;
    
    public:
        /* Constructions */
        Matrix(unsigned int m);

        /* Set Functions */
        void set_entry(unsigned int i, unsigned int j, Complex c);

        /* Get Functions */
        Complex get_entry(unsigned int i, unsigned int j) const;
        Complex** get_arr();
        unsigned int get_dim() const;

        /* Operators */
        Matrix operator+(Matrix const& op);
        Matrix operator-(Matrix const& op);
        Matrix operator*(Matrix const& op);
        Matrix operator*(Complex const& op);
        Matrix operator/(const int a);
        Matrix operator!();

        /* Misc */
        bool is_unitary() const;
        void resize(unsigned int m);

        /* Displays */
        void show();

        /* Tensors */
        Matrix kronecker_product(Matrix sample);
        Matrix kronecker_fill(unsigned int place, unsigned int regs);
        Matrix kronecker_control_fill(unsigned int control, unsigned int target, unsigned int regs);

        /* Friend Class */
        friend class State;
        friend std::ostream &operator<<(std::ostream &os, Matrix const &m)
};

#endif