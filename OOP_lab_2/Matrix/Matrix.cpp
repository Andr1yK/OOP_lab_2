//
//  Matrix.cpp
//  OOP_lab_2
//
//  Created by Andriy Kobetiak on 29.09.2022.
//

#include<iostream>
#include <sstream>
#include "Matrix.hpp"

using namespace std;

// --- INIT ---

bool Matrix::init(int rows, int columns) {
  if (!Matrix::isValid(rows, columns)) {
    return false;
  }

  this->_rows = rows;
  this->_columns = columns;

  this->allocateMemory();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      this->matrix[i][j] = 0;
    }
  }

  return true;
}

void Matrix::read() {
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      
      printf("matrix[%i][%i]: ", i, j);
      cin >> this->matrix[i][j];
    }

    cout << endl;
  }
}

// ---  GETTERS ---

unsigned int const Matrix::getRowsCount() {
  return this->_rows;
}

unsigned int const Matrix::getcolumnsCount() {
  return this->_columns;
}

void const Matrix::displау() {
  for (int i = 0; i < this->_rows; i++)
    for (int j = 0; j < this->_columns; j++)
      cout << this->matrix[i][j] << " \n"[j == this->_columns-1];
}

// --- OPERATIONS ---

string const Matrix::toString() {
  stringstream stream;

  for (int i = 0; i < this->_rows; i++)
    for (int j = 0; j < this->_columns; j++) {
         stream << this->matrix[i][j] << '\t';
     stream << '\n';
  }

  return stream.str();
}

Matrix Matrix::add(Matrix& firstMatrix, Matrix& secondMatrix)
{
  if (firstMatrix._rows != secondMatrix._rows
      || firstMatrix._columns != secondMatrix._columns) {
    exit(EXIT_FAILURE);
  }

  Matrix temp;
  temp.init(firstMatrix._rows, firstMatrix._columns);

  for (int i = 0; i < firstMatrix._rows; ++i)
    for (int j = 0; j < firstMatrix._columns; ++j)
      temp.matrix[i][j] = firstMatrix.matrix[i][j] + secondMatrix.matrix[i][j];

  return temp;
}

Matrix Matrix::subtract(Matrix& firstMatrix, Matrix& secondMatrix)
{
  if (firstMatrix._rows != secondMatrix._rows
      || firstMatrix._columns != secondMatrix._columns) {
    exit(EXIT_FAILURE);
  }

  Matrix temp;
  temp.init(firstMatrix._rows, firstMatrix._columns);

  for (int i = 0; i < firstMatrix._rows; ++i) {
    for (int j = 0; j < firstMatrix._columns; ++j) {
      temp.matrix[i][j] = firstMatrix.matrix[i][j] - secondMatrix.matrix[i][j];
    }
  }

  return temp;
}

Matrix& Matrix::multiply(double number) {
  for (int i = 0; i < this->_rows; ++i) {
    for (int j = 0; j < this->_columns; ++j) {
      this->matrix[i][j] *= number;
    }
  }

  return *this;
}

double const getByIndexes(
  const Matrix& matrixRef,
  unsigned int row,
  unsigned int column
) {
  return matrixRef.matrix[row][column];
}

// --- HELPERS ---

void Matrix::allocateMemory() {
  this->matrix = new double*[this->_rows];

  for (int i = 0; i < this->_rows; ++i) {
    this->matrix[i] = new double[this->_columns];
  }
}

bool Matrix::isValid(int rows, int columns) {
  return rows > 0 && columns > 0;
}

void Matrix::destructor() {
  for (int i = 0; i < this->_rows; ++i) {
    delete[] this->matrix[i];
  }

  delete[] this->matrix;
}
