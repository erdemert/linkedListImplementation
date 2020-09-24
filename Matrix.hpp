#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <cstdlib>

#include "LinkedList.hpp"

// DO NOT CHANGE THIS FILE.

class Matrix {
public:
    Matrix(int nor, int noc);
    Matrix(int nor, int noc, std::string elements);

    int getElementByIndex(int rowIndex, int columnIndex) const;
    void setElementByIndex(int rowIndex, int columnIndex, int element);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const int &rhs) const;

    Matrix kroneckerProduct(const Matrix &rhs) const;

    void print();

private:
    int numberOfRows;
    int numberOfColumns;

    LinkedList<int> matrix;
};

#endif //POLYNOMIAL_HPP
