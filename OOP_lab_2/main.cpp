//
//  main.cpp
//  OOP_lab_2
//
//  Created by Andriy Kobetiak on 29.09.2022.
//

#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main() {
  // --- INIT ---
  Matrix matrix1;
  Matrix matrix2;
  Matrix addedMatrixResult;
  Matrix subtractMatrixResult;
  Matrix subtractMatrixResult2;
  
  unsigned int rows;
  unsigned int columns;
  
  cout << "rows count: "; cin >> rows;
  cout << "columns count: "; cin >> columns;
  cout << endl;

  // --- FILL ---
  cout << "INIT MATRIX №1\n";
  matrix1.init(rows, columns);
  matrix1.read();

  cout << "\nINIT MATRIX №2\n";
  matrix2.init(rows, columns);
  matrix2.read();

  // --- DISPLAY ---
  cout << "MATRIX_1:\n";
  matrix1.displау();

  cout << "\nMATRIX_2:\n";
  matrix2.displау();

  // --- OPERATIONS ---
  // -- ADD --
  cout << "\nMATRIX_3 - Add MATRIX_1 and MATRIX_2:\n";
  addedMatrixResult = Matrix::add(matrix1, matrix2);
  addedMatrixResult.displау();

  // -- SUBTRACT --
  cout << "\nSubtract MATRIX_2 from MATRIX_3:\n";
  subtractMatrixResult = Matrix::subtract(addedMatrixResult, matrix2);
  subtractMatrixResult.displау();

  // -- MULTTIPLY --
  cout << "\nMultiply MATRIX_1 by 4:\n";
  matrix1.multiply(4);
  matrix1.displау();

  // -- SUBTRACT --
  cout << "\nSubtract MATRIX_2 from MATRIX_1 (after multiply):\n";
  subtractMatrixResult2 = Matrix::subtract(matrix1, matrix2);
  subtractMatrixResult2.displау();

  // -- CONVERT TO STRING --
  cout << "\nStringifyed MATRIX_3:\n";
  cout << addedMatrixResult.toString() << endl;

  // -- GET VALUE BY INDEXES --
  printf("\nMATRIX_3[0][0]: %.2f \n\n", getByIndexes(addedMatrixResult, 0, 0));

  // --- DESTRUCTORS ---
  subtractMatrixResult2.destructor();
  subtractMatrixResult.destructor();
  addedMatrixResult.destructor();
  matrix1.destructor();
  matrix2.destructor();

  return 0;
}
