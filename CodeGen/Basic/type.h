#ifndef TYPE_H
#define TYPE_H
#include "complex.h"

struct Quantum
    {
        Complex a;
        Complex b;

        public:
        Quantum()
        {
            a = Complex(0, 0);
            b = Complex(0, 0);
        }

        Quantum(Complex a, Complex b)
        {
            this->a = a;
            this->b = b;
        }
    };

#endif TYPE_H