#include <vector>
#include <iostream>
#include <numeric>
#include "complex.h"
#include "matrix.h"

/* Add/Sub Functions */
/* Add and Sub two lists of unsigned integers, integers, floats, complex numbers and matrices */
template <typename T>
std::vector<T> addLists(const std::vector<T> list1, std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    std::vector<T> result;
    for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] + list2[i]);

    return result;
}

template <typename T>
std::vector<T> addLists(const std::vector<T> list1, std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    std::vector<T> result;
    for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] - list2[i]);

    return result;
}

// std::vector<unsigned int> addListsUnsigned(std::vector<unsigned int> list1, std::vector<unsigned int> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<unsigned int> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] + list2[i]);

//     return result;
// }

// std::vector<unsigned int> subListsUnsigned(std::vector<unsigned int> list1, std::vector<unsigned int> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<unsigned int> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] - list2[i]);

//     return result;
// }

// /* Add/Sub two lists of integers */
// std::vector<int> addListsInt(std::vector<int> list1, std::vector<int> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<int> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] + list2[i]);

//     return result;
// }

// std::vector<int> subListsInt(std::vector<int> list1, std::vector<int> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<int> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] - list2[i]);

//     return result;
// }

// /* Add/Sub two lists of floats */
// std::vector<float> addListsFloat(std::vector<float> list1, std::vector<float> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<float> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] + list2[i]);

//     return result;
// }

// std::vector<float> subListsFloat(std::vector<float> list1, std::vector<float> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<float> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] - list2[i]);

//     return result;
// }

// /* Add/Sub two lists of complex values */
// std::vector<Complex> addListsComplex(std::vector<Complex> list1, std::vector<Complex> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<Complex> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] + list2[i]);

//     return result;
// }

// std::vector<Complex> subListsComplex(std::vector<Complex> list1, std::vector<Complex> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<Complex> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] - list2[i]);

//     return result;
// }

// /* Add/Sub two lists of matrices */
// std::vector<Matrix> addListsMatrix(std::vector<Matrix> list1, std::vector<Matrix> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<Matrix> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] + list2[i]);          /* Matrix compatibility checked in operator overloading */

//     return result;
// }

// std::vector<Matrix> subListsMatrix(std::vector<Matrix> list1, std::vector<Matrix> list2) {
//     if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
//     std::vector<Matrix> result;
//     for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] - list2[i]);          /* Matrix compatibility checked in operator overloading */

//     return result;
// }

/* Dot Product */
/* Dot product of two lists of unsigned integers, integers and floats */
template <typename T>
float dotProduct(const std::vector<T> list1, const std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    float result = 0;
    for(int i = 0; i < list1.size(); i++) result += (list1[i] * list2[i]);

    return result;
}

/* Dot product of two lists of complex values */
Complex dotProductComplex(std::vector<Complex> list1, std::vector<Complex> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    Complex result;
    for(int i = 0; i < list1.size(); i++) {
        Complex temp = list1[i] * (!list2[i]);
        result = result + temp;
    }

    return result;
}

/* Dot product of list<matrix> and list<comples> */
Matrix dotProductCross(const std::vector<Complex> complexList, const std::vector<Matrix> matrixList) {
    if(complexList.size() != matrixList.size()) throw std::runtime_error("Error: Lists sizes do not match");

    Matrix result = Matrix(matrixList[0].get_dim());
    for(int i = 0; i < matrixList.size(); i++) {
        Matrix mat = matrixList[i];
        Complex comp = complexList[i];
        Matrix temp = mat*comp;
        result = result + temp;
    }

    return result;
}

/* Sum (till floats) */
template <typename T>
T sum(const std::vector<T> list) {
    return std::reduce(list.begin(),list.end());
}

/* Mean (till floats) */
template <typename T>
float mean(const std::vector<T> list) {
    return sum(list)/float(list.size());
}

/* Variance (till floats) */
template <typename T>
float variance(const std::vector<T> list) {
    if(list.size() == 0) return 0.0;
    float avg = mean(list);

    float variance = 0;
    for(const auto x : list) variance += ((x - avg)*(x - avg))/float(list.size());

    return variance;
}

/* Standard Deviation (till floats) */
template <typename T>
float stdDev(const std::vector<T> list) {
    return sqrt(variance(list));
}

/* Sum (complex, matrices) */
Complex sumComplex(const std::vector<Complex> list) {
    Complex result = Complex(0,0);
    for(const auto c : list) result = result + c;

    return result;
}

Matrix sumMatrix(const std::vector<Matrix> list) {
    Matrix result = Matrix(list[0].get_dim());
    for(const auto m : list) result = result + m;

    return result;
}

/* Mean (complex, matrices) */
Complex meanComplex(const std::vector<Complex> list) {
    return sumComplex(list)/float(list.size());
}

Matrix meanMatrix(const std::vector<Matrix> list) {
    return sumMatrix(list)/float(list.size());
}

/* Condenser function */
