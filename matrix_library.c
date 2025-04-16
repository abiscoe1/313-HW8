#include <stdio.h>

void addMatrices(int row1, int col1, int row2, int col2, int matrix1[][col1],
		 int matrix2[][col2], int result[][col1]){
  // If the matrices aren't the same size you can't add them
  if (row1 != row2){
    if (col1 != col2){
      printf("Invalid matrix sizes. \n");
      return;
    }
  }
  for (int i = 0; i < row1; i++){
    for (int j = 0; j < col1; j++)
      result[i][j] = matrix1[i][j] + matrix2[i][j];
  }
}

void subMatrices(int row1, int col1, int row2, int col2, int matrix1[][col1],
		 int matrix2[][col2], int result[][col1]){
  // If the matrices aren't the same size you can't subtract them
  if (row1 != row2){
    if (col1 != col2){
      printf("Invalid matrix sizes. \n");
      return;
    }
  }
  for (int i = 0; i < row1; i++){
    for (int j = 0; j < col1; j++)
      result[i][j] = matrix1[i][j] - matrix2[i][j];
  }
}

void multMatrices(int row1, int col1, int row2, int col2, int matrix1[][col1],
		  int matrix2[][col2], int result[row1][col2]){
  // Can't multiply matrices if the first matrix column size and the second
  // matrix row size aren't equal
  if (col1 != row2){
    printf("Invalid matrix sizes. \n");
    return;
  }
  
  // Initialize the result matrix
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      result[i][j] = 0;
    }
  }
  
  for (int i = 0; i < row1; i++){
    for (int j = 0; j < col2; j++){
      for (int k = 0; k < col1; k++){
	      result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

// Multiply and return the same matrix with the scalar applied
void multByConstant(int row, int col, int matrix[][col], int constant){
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      matrix[i][j] = matrix[i][j] * constant;
    }
  }
}

// Return the transpose of the matrix as the result
void transpose(int row, int col, int matrix[][col], int result[][row]){
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      result[j][i] = matrix[i][j];
    }
  }
}

void printMatrix(int row, int col, int matrix[][col]){
  int rowCount = 0;
  
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      printf("%d ", matrix[i][j]);
      rowCount++;
      // Start a new row if the number of entries in a row matches
      // the column size
      if (rowCount == col){
          rowCount = 0;
          printf("\n");
      }
    }
  }
}

int main(){
  int matrixA[2][2] = {{6, 4}, {8, 3}};
  int matrixB[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int matrixC[2][3] = {{2, 4, 6}, {1, 3, 5}};
  int matrixD[2][2];
  int transposedC[3][2];
  int result[2][2];
  
  printf("Transpose of Matrix C: \n");
  transpose(2, 3, matrixC, transposedC);
  printMatrix(3, 2, transposedC);
  printf("\n");
  
  printf("Matrix B Multiplied by 3: \n");
  multByConstant(2, 3, matrixB, 3);
  printMatrix(2, 3, matrixB);
  printf("\n");
  
  printf("New Matrix B and Transposed Matrix C Multiplied: \n");
  multMatrices(2, 3, 3, 2, matrixB, transposedC, result);
  printMatrix(2, 2, result);
  printf("\n");
  
  printf("Result of Multiplication Added to Matrix A for Solution D: \n");
  addMatrices(2, 2, 2, 2, matrixA, result, matrixD);
  printMatrix(2, 2, matrixD);
  
  return 0;
}
