#include <iostream>
#include "complex.h"
#include "matrix.h"
#include "state.h"
#include "math.h"

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
    Y.set_entry(1, 0, Complex(0, 1));
    Y.set_entry(1, 1, Complex(0, 0));
    Y.show();

    // Y.set_entry(0, 0, Complex(0, 0));
    // Y.set_entry(0, 1, Complex(0, -1));
    // Y.set_entry(1, 0, Complex(0, 5));
    // Y.set_entry(1, 1, Complex(0, 0));
    // Y.show();

    // Matrix A = X*Y;
    // A.show();
    // Matrix A_T = !A;
    // A_T.show();

    // cout << Y.is_unitary() << endl;

    State sample = State(1);
    sample.set_entry(0, Complex(1, 0));
    sample.set_entry(1, Complex(1, 0));
    sample.normalize();
    State on_x = sample.transform(X);
    State on_y = sample.transform(Y);

    sample.show();
    on_x.show();
    on_y.show();

    Matrix comp = X.kronecker_product(Y);
    Matrix filled = X.kronecker_fill(2, 3);

    comp.show();
    filled.show();
    

    return 0;
}