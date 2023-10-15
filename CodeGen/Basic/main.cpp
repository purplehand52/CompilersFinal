#include <iostream>
#include "complex.h"
#include "matrix.h"

using namespace std;

int main()
{
    // Complex a = Complex(3, 5);
    // Complex b = Complex(12, -5);
    // cout << b.to_str() << endl;
    // Complex c = !b;
    // cout << c.to_str() << endl;
    // Complex c = b/a;

    // cout << c.to_str() << endl;
    // cout << b.get_norm() << endl;

    Matrix X = Matrix(2);
    Matrix Y = Matrix(2);
    
    X.set_entry(0, 0, Complex(0, 0));
    X.set_entry(0, 1, Complex(1, 0));
    X.set_entry(1, 0, Complex(1, 0));
    X.set_entry(1, 1, Complex(0, 0));
    X.show();

    Y.set_entry(0, 0, Complex(0, 0));
    Y.set_entry(0, 1, Complex(0, -1));
    Y.set_entry(1, 0, Complex(0, 5));
    Y.set_entry(1, 1, Complex(0, 0));
    Y.show();

    Matrix A = X*Y;
    A.show();
    Matrix A_T = !A;
    A_T.show();

    cout << Y.is_unitary() << endl;

    return 0;
}