#include <iostream>
#include <stdexcept>
#include "matrix.h"
#include "math.h"

/* Helpers */
unsigned int pow_two(unsigned int n)
{
    if(n == 0) return -1;
    if(n & (n - 1)) return -1;
    return floor(log2(n));
}

/* Constructors */
Matrix::Matrix(unsigned int n)
{
    this->n = n;
    this->arr = (Complex*)malloc(n*n*sizeof(Complex));
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            if(i == j) this->arr[i*this->n+j] = Complex(1, 0);
            else this->arr[i*this->n+j] = Complex();
        }
    }
}

/* Set Functions */
void Matrix::set_entry(unsigned int i, unsigned int j, Complex c)
{
    if((i >= n) || (j >= n)) throw std::invalid_argument("Out of bounds!!!");
    this->arr[i*this->n+j] = c;
}

/* Get Function */
Complex Matrix::get_entry(unsigned int i, unsigned int j) const
{
    if((i >= n) || (j >= n)) throw std::invalid_argument("Out of bounds!!!");
    return this->arr[i*this->n+j];
}

unsigned int Matrix::get_dim() const
{
    return this->n;
}

/* Operators */
Matrix Matrix::operator+(Matrix const& op)
{
    if(this->n != op.get_dim()) throw std::invalid_argument("Incompatible Matrices!");
    Matrix ans = Matrix(this->n);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            ans.set_entry(i, j, this->arr[i*this->n+j] + op.get_entry(i,j));
        }
    }
    return ans;
}

Matrix Matrix::operator-(Matrix const& op)
{
    if(this->n != op.get_dim()) throw std::invalid_argument("Incompatible Matrices!");
    Matrix ans = Matrix(this->n);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            ans.set_entry(i, j, this->arr[i*this->n+j] - op.get_entry(i,j));
        }
    }
    return ans;
}

Matrix Matrix::operator*(Matrix const& op)
{
    if(this->n != op.get_dim()) throw std::invalid_argument("Incompatible Matrices!");
    Matrix ans = Matrix(this->n);
    Complex temp;
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            temp = Complex();
            for(int k = 0; k < this->n; k++)
            {
                temp = temp + this->arr[i*this->n+k] * op.get_entry(k, j);
            }
            ans.set_entry(i, j, temp);
        }
    }
    return ans;
}

Matrix Matrix::operator!()
{
    Matrix ans = Matrix(this->n);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            ans.set_entry(j, i, !this->arr[i*this->n+j]);
        }
    }
    return ans;
}

/* Misc */
bool Matrix::is_unitary() const
{
    Matrix cpy = *this;
    Matrix ans = (!cpy)*(cpy);
    ans.show();
    Matrix eye = Matrix(this->n);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            if(eye.get_entry(i, j) != ans.get_entry(i, j)) return false;
        }
    }
    return true;
}

/* Show */
void Matrix::show()
{
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            std::cout << arr[i*this->n+j].to_str() << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

/* Kronecker product */
Matrix Matrix::kronecker_product(Matrix sample) /* Computes [THIS # SAMPLE] */
{
    //if((pow_two(n) < 0) || (pow_two(sample.n) < 0)) throw std::invalid_argument("Incompatible Matrices for Kronecker-Product!");

    Matrix ans = Matrix(n * sample.n);
    Complex temp;

    /* Compute */
    for(int out_i = 0; out_i < n; out_i++)
    {
        for(int out_j = 0; out_j < n; out_j++)
        {
            temp = arr[out_i*n + out_j];
            for(int inn_i = 0; inn_i < sample.n; inn_i++)
            {
                for(int inn_j = 0; inn_j < sample.n; inn_j++)
                {
                    //ans.arr[out_i*n + inn_i][out_j*n + inn_j]
                    ans.arr[(out_i*n + inn_i)*n*sample.n + out_j*n + inn_j] = temp * sample.arr[inn_i*sample.n + inn_j];
                }
            }
        }
    }

    /* Return */
    return ans;
}

/* Kronecker Fill */
Matrix Matrix::kronecker_fill(unsigned int place, unsigned int regs) /* Only for 2*2 matrices */
{
    if(n != 2) throw std::invalid_argument("Incompatible Matrices for Kronecker-Fill!");

    Matrix ans = Matrix(2);

    /* Compute */
    for(int i = 1; i <= regs; i++)
    {
        if(i != place) ans = ans.kronecker_product(Matrix(2));
        else ans = ans.kronecker_product(*this);
    }

    /* Return */
    return ans;
}