#ifndef LIST_FUNC_H
#define LIST_FUNC_H
#include <vector>
#include <iostream>
#include <numeric>
#include "complex.h"
#include "matrix.h"
#include <math.h>


/* Add/Sub Functions */
/* Add and Sub two lists of unsigned integers, integers, floats, complex numbers and matrices */
template <typename T>
std::vector<T> add(std::vector<T> list1, std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    std::vector<T> result;
    for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] + list2[i]);

    return result;
}

template <typename T>
std::vector<T> sub(std::vector<T> list1, std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    std::vector<T> result;
    for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] - list2[i]);

    return result;
}

/* Dot Product */
/* Dot product of two lists of unsigned integers, integers and floats */
template <typename T>
float dot(std::vector<T> list1,std::vector<T> list2) {
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
float avg(const std::vector<T> list) {
    return sum(list)/float(list.size());
}

/* Variance (till floats) */
template <typename T>
float var(const std::vector<T> list) {
    if(list.size() == 0) return 0.0;
    float avg_ = avg(list);

    float variance = 0;
    for(const auto x : list) variance += ((x - avg_)*(x - avg_))/float(list.size());

    return variance;
}

/* Standard Deviation (till floats) */
template <typename T>
float std_dev(const std::vector<T> list) {
    return sqrt(var(list));
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

/* Bitwise Operators */
template <typename T>
std::vector<T> bitwiseAnd(const std::vector<T> list1, const std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    std::vector<T> result;
    for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] & list2[i]);

    return result;
}

template <typename T>
std::vector<T> bitwiseOr(const std::vector<T> list1, const std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    std::vector<T> result;
    for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] | list2[i]);

    return result;
}

template <typename T>
std::vector<T> bitwiseXor(const std::vector<T> list1, const std::vector<T> list2) {
    if(list1.size() != list2.size()) throw std::runtime_error("Error: Lists sizes do not match");
    
    std::vector<T> result;
    for(int i = 0; i < list1.size(); i++) result.push_back(list1[i] ^ list2[i]);

    return result;
}

/* Condenser function */
/* Number of ones in binary representation of number */
unsigned int numOnes(unsigned int num) {
    unsigned int count = 0;
    while(num) {
        count += num & 1;
        num = num>>1;
    }

    return count;
}

/* Least power of 2 greater than a number */
unsigned int nextPowerOf2(unsigned int num) {
    unsigned int count = 0;
    if(num && !(num & (num - 1))) return num;
    while(num != 0) {
        num = num>>1;
        count += 1;
    }

    return 1 << count;
}


/* Extract specific multiple bits from a number */
unsigned int extractBits(unsigned int num, unsigned int place) {
    unsigned int result = 0;
    unsigned int count = 0;
    unsigned int temp = 1;
    while(temp <= num) {
        if((temp & place) != 0) {
            result += (num & temp) >> count;
        }
        else count++;
        temp = temp << 1;
    }

    return result;
}

/* Condense a list of unsigned integers */
std::vector<unsigned int> condense(const std::vector<unsigned int> list, unsigned int place) {
    /* New size */
    unsigned int n_size = nextPowerOf2(list.size())/(1<<numOnes(place));
    
    std::vector<unsigned int> result(n_size,0);

    /* Iterate and condense */
    unsigned int comp_place = nextPowerOf2(list.size()) - place - 1;
    for(int i = 0; i < list.size(); i++) {
        unsigned int index = extractBits(i,comp_place);
        result[index] += list[i];
    }

    return result;
}

/* repeat string */
std::string repeatString(std::string str, int n) {
    std::string result = "";
    for(int i = 0; i < n; i++) result += str;

    return result;
}

#endif