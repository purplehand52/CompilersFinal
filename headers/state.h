#ifndef STATE_H
#define STATE_H

#include "complex.h"
#include "matrix.h"
#include "type.h"
#include <stdbool.h>

class StateVec
{
    private:
        unsigned int regs;
        Complex* arr;

    public:
        /* Constructions */
        StateVec(unsigned int n);
        StateVec(unsigned int n, struct Quantum* q);

        /* Set Functions */
        void set_entry(unsigned int i, Complex c);

        /* Get Functions */
        Complex get_value(unsigned int i);
        Complex* get_arr();
        unsigned int get_dim() const;

        /* Functions */
        StateVec transform(Matrix sample);
        void normalize();
        int measure_prob(unsigned int target);

        /* Show */
        void show();

        friend std::ostream& operator<<(std::ostream& os, const StateVec& state);
};

#endif