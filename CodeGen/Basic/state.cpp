#include "state.h"
#include <stdexcept>
#include <iostream>
#include <math.h>

State::State(unsigned int n)
{
    if(n == 0) throw std::invalid_argument("Cannot have 0 quantum registers!");
    this->regs = n;
    this->arr = (Complex*)malloc((1<<n)*sizeof(Complex));
    arr[0] = Complex(1, 0);
    for(int i = 1; i < (1<<n); i++) arr[i] = Complex();
}

/* Set Functions */
void State::set_entry(unsigned int i, Complex c)
{
    if(i >= (1<<regs)) throw std::invalid_argument("Out of bounds!");
    this->arr[i] = c;
}

/* Get Functions */
// Complex State::get_value(unsigned int i)
// {
//     if(i >= (1<<n)) throw std::invalid_argument("Out of bounds!");
//     return this->arr[i];
// }

unsigned int State::get_dim() const
{
    return this->regs;
}

/* Transform */
State State::transform(Matrix sample)
{
    if((1 << regs) != sample.get_dim()) throw std::invalid_argument("Matrix and State are not compatible!");

    /* Initialisation */
    Complex* ops = sample.arr;
    unsigned int dim = sample.get_dim();
    State ans = State(regs);
    unsigned int offset;
    Complex temp;

    /* Compute */
    for(int i = 0; i < dim; i++)
    {
        offset = i*dim;
        temp = Complex();
        for(int j = 0; j < dim; j++) temp = temp + ops[offset+j]*arr[j];
        ans.arr[i] = temp;
    }

    /* Return */
    return ans;
}

/* Normalize */
void State::normalize()
{
    float prob_sum = 0;
    for(int i = 0; i < (1 << regs); i++) prob_sum = prob_sum + (arr[i].get_norm()*arr[i].get_norm());
    Complex temp = Complex(sqrt(prob_sum), 0);
    for(int j = 0; j < (1 << regs); j++) arr[j] = arr[j]/temp;
}

/* Show */
void State::show()
{
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < (1 << this->regs); i++)
    {
        std::cout << arr[i].to_str() << "\t";
    }
    std::cout << "\n--------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}