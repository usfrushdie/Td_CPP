#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <stdexcept>
#include <iostream>

template<typename T>
class MatrixBase {
public:
    MatrixBase();
    MatrixBase(size_t _rows, size_t _cols);
    
    void addElement(T element);
    T getElement(int row, int col) const;
    
    size_t getRows() const;
    size_t getCols() const;
    
    void Display() const;

private:
    size_t rows;
    size_t cols;
    std::vector<T> data;
};

// Implémentation des méthodes de MatrixBase

template<typename T>
MatrixBase<T>::MatrixBase() : rows(0), cols(0) {}

template<typename T>
MatrixBase<T>::MatrixBase(size_t _rows, size_t _cols) : rows(_rows), cols(_cols), data(_rows * _cols) {}

template<typename T>
void MatrixBase<T>::addElement(T element) {
    if (data.size() < rows * cols) {
        data.push_back(element);
    } else {
        throw std::out_of_range("La matrice est pleine.");
    }
}

template<typename T>
T MatrixBase<T>::getElement(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Indice hors limites.");
    }
    return data[row * cols + col];
}

template<typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template<typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}

template<typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << data[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif
