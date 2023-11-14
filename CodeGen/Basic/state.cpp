#include "state.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <math.h>

StateVec::StateVec(unsigned int n)
{
    if(n == 0) throw std::invalid_argument("Cannot have 0 quantum registers!");
    this->regs = n;
    this->arr = (Complex*)malloc((1<<n)*sizeof(Complex));
    arr[0] = Complex(1, 0);
    for(int i = 1; i < (1<<n); i++) arr[i] = Complex();
}

/* Set Functions */
void StateVec::set_entry(unsigned int i, Complex c)
{
    if(i >= (1<<regs)) throw std::invalid_argument("Out of bounds!");
    this->arr[i] = c;
}

/* Get Functions */
Complex StateVec::get_value(unsigned int i)
{
    if(i >= (1<<regs)) throw std::invalid_argument("Out of bounds!");
    return this->arr[i];
}

unsigned int StateVec::get_dim() const
{
    return this->regs;
}

/* Transform */
StateVec StateVec::transform(Matrix sample)
{
    if((1 << regs) != sample.get_dim()) throw std::invalid_argument("Matrix and State are not compatible!");

    /* Initialisation */
    unsigned int dim = sample.get_dim();
    StateVec ans = StateVec(regs);
    unsigned int offset;
    Complex temp;

    /* Compute */
    for(int i = 0; i < dim; i++)
    {
        temp = Complex();
        for(int j = 0; j < dim; j++) temp = temp + sample.get_entry(i,j)*arr[j];
        ans.arr[i] = temp;
    }

    /* Return */
    return ans;
}

/* Normalize */
void StateVec::normalize()
{
    float prob_sum = 0;
    for(int i = 0; i < (1 << regs); i++) prob_sum = prob_sum + (arr[i].get_norm()*arr[i].get_norm());
    Complex temp = Complex(sqrt(prob_sum), 0);
    for(int j = 0; j < (1 << regs); j++) arr[j] = arr[j]/temp;
}

/* Measure */
/* Note: Represents probability of getting |0> */
int StateVec::measure_prob(unsigned int target)
{
    /* Normalize */
    this->normalize();

    /* Other stuff */
    unsigned int comp = (1<<target);
    float prob = 0;
    for(int i = 0; i < (1<<regs); i++) 
    {
        if(comp & i) prob += arr[i].get_norm()*arr[i].get_norm();
    }

    /* Choose */
    int result;
    Complex norm_const = Complex(sqrt(prob), 0);
    float sample = (float) rand()/RAND_MAX;
    (prob > sample) ? (result = 1) : (result = 0);
    std::cout << prob << std::endl;

    /* Change State */
    Complex* new_st = (Complex*)malloc((1<<(regs-1))*sizeof(Complex));
    int j = 0;
    for(int k = 0; k < (1<<regs); k++) 
    {
        if(comp & k)
        {
            new_st[j] = arr[k]/norm_const;
            j++;
        }
    }

    /* Modify */
    regs = regs - 1;
    if(regs != 0)
    {
        Complex* temp = arr;
        arr = new_st;
        free(temp);
    }
    else
    {
        free(arr);
        arr = NULL;
    }
    

    return result;
}

/* Show */
void StateVec::show()
{
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < (1 << this->regs); i++)
    {
        std::cout << arr[i].to_str() << "\t";
    }
    std::cout << "\n--------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}