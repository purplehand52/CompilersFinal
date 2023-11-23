#include <iostream>
#include "complex.h"
#include "matrix.h"
#include "state.h"
#include "math.h"
#include "list_func.h"
#include <time.h>

using namespace std;

int main()
{
    /* Seed */
    srand(time(NULL));

    /* Operators */
    Matrix X = Matrix(2);
    Matrix Y = Matrix(2);
    Matrix Z = Matrix(2);
    
    X.set_entry(0, 0, Complex(0, 0));
    X.set_entry(0, 1, Complex(1, 0));
    X.set_entry(1, 0, Complex(1, 0));
    X.set_entry(1, 1, Complex(0, 0));
    // X.show();

    Y.set_entry(0, 0, Complex(0, 0));
    Y.set_entry(0, 1, Complex(0, -1));
    Y.set_entry(1, 0, Complex(0, 1));
    Y.set_entry(1, 1, Complex(0, 0));
    // Y.show();

    Z.set_entry(0, 0, Complex(1, 0));
    Z.set_entry(0, 1, Complex(0, 0));
    Z.set_entry(1, 0, Complex(-1, 0));
    Z.set_entry(1, 1, Complex(0, 0));
    // Y.show();

    /* State (Stage 0) */
    struct Quantum q[2];
    q[1].a = Complex(1/sqrt(2), 0);
    q[1].b = Complex(1/sqrt(2), 0);
    q[0].a = Complex(1, 0);
    q[0].b = Complex(0, 0);
    StateVec sample = StateVec(2, q);
    sample.show();
    
    /* Stage 1 */
    // Matrix op = X.kronecker_control_fill(2, 1, 2);
    // op.show();
    // StateVec after_X = sample.transform(X.kronecker_control_fill(2, 1, 2));
    // after_X.show();

    /* Measure */
    int result = sample.measure_prob(0);
    cout << result << endl;
    sample.show();

    /* State (Stage 1)*/
    // 
    // op.show();
    // StateVec after_X = sample.transform(X.kronecker_control_fill(2, 1, 2));
    // after_X.show();
    
    /* Measure */
    // int result = after_X.measure_prob(0);
    // cout << result << endl;

    vector<unsigned int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                                 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vector<unsigned int> list_new = condense(list, 3);
    for(int i = 0; i < list_new.size(); i++) {
        cout << list_new[i] << " ";
    }

    return 0;   
}