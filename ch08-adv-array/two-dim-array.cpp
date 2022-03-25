#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// utility
int **makeSampleMatrix(int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
void cleanMatrix(int **matrix, int rows);

// in-place algorithms
void transposeSquare(int **matrix, int rows, int cols);
void flipH(int **matrix, int rows, int cols);
void flipV(int **matrix, int rows, int cols);

// out-of-place algorithms
int **transpose(int **matrix, int rows, int cols);
int **rotateCW90(int **matrix, int rows, int cols);

//////////////////
// Implementations
//////////////////

void printMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << setw(2) << matrix[i][j] << " ";
    cout << endl;
  }
}

int **makeSampleMatrix(int rows, int cols) {
  int **matrix = new int *[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
    for (int j = 0; j < cols; j++)
      matrix[i][j] = i * rows + j + 1;
  }
  return matrix;
}

void cleanMatrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++)
    delete [] matrix[i];
  delete [] matrix;
}

void transposeSquare(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows - 1; i++)
    for (int j = i + 1; j < cols; j++)
      swap(matrix[i][j], matrix[j][i]);
}

void flipH(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols / 2; j++)
      swap(matrix[i][j], matrix[i][cols - 1 - j]);
}

void flipV(int **matrix, int rows, int cols) {
  for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows / 2; i++)
      swap(matrix[i][j], matrix[rows - 1 - i][j]);
}

int **transpose(int **matrix, int rows, int cols) {
  int **result;
  result = new int *[cols];
  for (int i = 0; i < cols; i++)
    result[i] = new int[rows];

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      result[j][i] = matrix[i][j];

  return result;
}

int ** rotateCW90(int **matrix, int rows, int cols) {
  int **result;
  result = new int *[cols];
  for (int i = 0; i < cols; i++)
    result[i] = new int[rows];

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      result[j][rows - 1 - i] = matrix[i][j];

  return result;
}

void testTranspose() {
  int rows = 2;
  int cols = 3;
  int **matrix = makeSampleMatrix(rows, cols);

  cout << "\nTesting transpose\n";
  cout << "Original\n";
  printMatrix(matrix, rows, cols);
  int **result = transpose(matrix, rows, cols);
  cout << "After transpose (out-of-place)\n";
  printMatrix(result, cols, rows);
  cleanMatrix(matrix, rows);
  cleanMatrix(result, cols);

  rows = 4;
  cols = 4;
  matrix = makeSampleMatrix(rows, cols);
  cout << "Original\n";
  printMatrix(matrix, rows, cols);
  transposeSquare(matrix, rows, cols);
  cout << "After transpose (in-place)\n";
  printMatrix(matrix, rows, cols);
  cleanMatrix(matrix, rows);

}

void testRotate() {
  int rows = 2;
  int cols = 3;
  int **matrix = makeSampleMatrix(rows, cols);

  cout << "\nTesting rotation\n";
  cout << "Original\n";
  printMatrix(matrix, rows, cols);
  int **result = rotateCW90(matrix, rows, cols);
  cout << "After clockwise rotation of 90 degree\n";
  printMatrix(result, cols, rows);
  cleanMatrix(matrix, rows);
  cleanMatrix(result, cols);
}

void testFlip() {
  int rows = 2;
  int cols = 3;
  int **matrix = makeSampleMatrix(rows, cols);

  cout << "\nTesting flipping\n";
  cout << "Original\n";
  printMatrix(matrix, rows, cols);
  flipH(matrix, rows, cols);
  cout << "After horizontal flipping\n";
  printMatrix(matrix, rows, cols);
  flipV(matrix, rows, cols);
  cout << "After vertical flipping\n";
  printMatrix(matrix, rows, cols);
  cleanMatrix(matrix, rows);

}

int main() {
  testTranspose();
  testFlip();
  testRotate();
  return EXIT_SUCCESS;
}