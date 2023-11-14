#ifndef STATE_H
#define STATE_H

#include "complex.h"
#include "matrix.h"
#include <stdbool.h>

class State
{
    private:
        unsigned int regs;
        Complex* arr;

    public:
        /* Constructions */
        State(unsigned int n);

        /* Set Functions */
        void set_entry(unsigned int i, Complex c);

        /* Get Functions */
        // Complex get_value(unsigned int i);
        unsigned int get_dim() const;

        /* Functions */
        State transform(Matrix sample);
        void normalize();

        /* Show */
        void show();
};

#endif