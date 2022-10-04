//
//  Matrix.hpp
//  OOP_lab_2
//
//  Created by Andriy Kobetiak on 29.09.2022.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>

class Matrix {
private:
  unsigned int _rows;
  unsigned int _columns;
  double **matrix;

protected:
// --- HELPERS ---
  void allocateMemory();
  static bool isValid(int, int);
  
public:
// --- INIT ---
  bool init(int, int);
  void read();

// --- GETTERS ---
  unsigned int const getRowsCount();
  unsigned int const getcolumnsCount();
  void const displау();

// --- OPERATIONS ---
  std::string const toString();

  static Matrix add(Matrix&, Matrix&);
  static Matrix subtract(Matrix&, Matrix&);

  Matrix& multiply(double);

  friend double const getByIndexes(const Matrix&, unsigned int, unsigned int);

// --- HELPERS ---
  void destructor();
};

#endif /* Matrix_hpp */


