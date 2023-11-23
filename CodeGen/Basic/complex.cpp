#include "complex.h"
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return std::move(out).str();
}

/* Constructors */
Complex::Complex()
{
    this->real = 0;
    this->imag = 0;
}

Complex::Complex(float a, float b)
{
    this->real = a;
    this->imag = b;
}

/* Set Functions */
void Complex::set_real(float r)
{
    this->real = r;
}

void Complex::set_imag(float i)
{
    this->imag = i;
}

/* Get Functions */
float Complex::get_real() const
{
    return this->real;
}

float Complex::get_imag() const
{
    return this->imag;
}

float Complex::get_norm() const
{
    return sqrt((this->real)*(this->real) + (this->imag)*(this->imag));
}

/* Operators */
Complex Complex::operator+(Complex const& op)
{
    Complex ans;
    ans.set_real(this->real + op.get_real());
    ans.set_imag(this->imag + op.get_imag());
    return ans;
}

Complex Complex::operator-(Complex const& op)
{
    Complex ans;
    ans.set_real(this->real - op.get_real());
    ans.set_imag(this->imag - op.get_imag());
    return ans;
}

Complex Complex::operator*(Complex const& op)
{
    Complex ans;
    ans.set_real((this->real)*op.get_real() - (this->imag)*op.get_imag());
    ans.set_imag((this->real)*op.get_imag() + (this->imag)*op.get_real());
    return ans;
}

Complex Complex::operator/(Complex const& op)
{
    Complex ans;
    float den = (op.real)*(op.real) + (op.imag)*(op.imag);
    ans.set_real(((this->real)*op.get_real() + (this->imag)*op.get_imag())/den);
    ans.set_imag((-(this->real)*op.get_imag() + (this->imag)*op.get_real())/den);
    return ans;
}

Complex Complex::operator/(const int a)
{
    Complex ans;
    ans.set_real(this->real/float(a));
    ans.set_imag(this->imag/float(a));
    return ans;
}

bool Complex::operator==(Complex const& op)
{
    if(this->real != op.get_real()) return false;
    else if(this->imag != op.get_imag()) return false;
    return true; 
}

bool Complex::operator!=(Complex const& op)
{
    if(this->real != op.get_real()) return true;
    else if(this->imag != op.get_imag()) return true;
    return false; 
}

Complex Complex::operator!()
{
    Complex ans;
    ans.set_real(this->real);
    ans.set_imag(-this->imag);
    return ans;
}

/* Show */
void Complex::show()
{
    if(this->imag >= 0) std::cout << this->real << " + " << this->imag << "i" << std::endl;
    else std::cout << this->real << " - " << -this->imag << "i" << std::endl;
}

std::string Complex::to_str()
{
    std::string o;
    if(this->imag >= 0) o = to_string_with_precision(this->real, 2) + " + " + to_string_with_precision(this->imag, 2) + "i";
    else o = to_string_with_precision(this->real, 2) + " - " + to_string_with_precision(-(this->imag), 2) + "i";

    // if(this->imag >= 0) o = std::format("{:.2f}", this->real) + " + " + std::format("{:.2f}", this->imag) + "i";
    // else o = std::format("{:.2f}", this->real) + " - " + std::format("{:.2f}", this->imag) + "i";

    // std::cout.precision(2);


    return o;
}