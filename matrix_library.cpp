#include <iostream>
#include <vector>
using namespace std;

class Matrix{
public:
  Matrix(){}
  
  void addMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2,
		   vector<vector<int>> &result){
    int row1 = matrix1.size();
    int col1 = matrix1[0].size();
    int row2 = matrix2.size();
    int col2 = matrix2[0].size();
    
    if ((row1 != row2) or (col1 != col2)){
      cout << "Invalid matrix sizes." << endl;
      return;
    }
    
    result.resize(row1, vector<int>(col1));
    
    for (int i = 0; i < row1; i++){
      for (int j = 0; j < col1; j++)
        result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  
  void subMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2,
		   vector<vector<int>> &result){
    int row1 = matrix1.size();
    int col1 = matrix1[0].size();
    int row2 = matrix2.size();
    int col2 = matrix2[0].size();
    
    if ((row1 != row2) or (col1 != col2)){
      cout << "Invalid matrix sizes." << endl;
      return;
    }
    
    result.resize(row1, vector<int>(col1));
    
    for (int i = 0; i < row1; i++){
      for (int j = 0; j < col1; j++)
        result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  
  void multMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2,
		    vector<vector<int>> &result){
    int row1 = matrix1.size();
    int col1 = matrix1[0].size();
    int row2 = matrix2.size();
    int col2 = matrix2[0].size();
    
    if ((row1 != col2) or (row2 != col1)){
      cout << "Invalid matrix sizes." << endl;
      return;
    }

    result.resize(row1, vector<int>(col2));

    for (int i = 0; i < row1; i++){
      for (int j = 0; j < col2; j++){
        for (int k = 0; k < col1; k++){
          result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
      }
    }
  }

  void multByConstant(vector<vector<int>> &matrix, int constant){
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++){
      for (int j = 0; j < col; j++){
        matrix[i][j] = matrix[i][j] * constant;
      }
    }
  }

  void transpose(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> result;
    result.resize(col, vector<int>(row));

    for (int i = 0; i < row; i++){
      for (int j = 0; j < col; j++){
        result[j][i] = matrix[i][j];
      }
    }

    matrix = result;
  }

  void printMatrix(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    int rowCount = 0;

    for (int i = 0; i < row; i++){
      for (int j = 0; j < col; j++){
        cout << matrix[i][j] << " ";
        rowCount++;
        if (rowCount == col){
          rowCount = 0;
          cout << endl;
        }
      }
    }
  }

};

int main(){
  vector<vector<int>> matrixA = {{6, 4}, {8, 3}};
  vector<vector<int>> matrixB = {{1, 2, 3}, {4, 5, 6}};
  vector<vector<int>> matrixC = {{2, 4, 6}, {1, 3, 5}};
  vector<vector<int>> matrixD;
  vector<vector<int>> result;

  Matrix functions;

  cout << "Transpose of Matrix C:" << endl;
  functions.transpose(matrixC);
  functions.printMatrix(matrixC);
  cout << endl;

  cout << "Matrix B Multiplied by 3:" << endl;
  functions.multByConstant(matrixB, 3);
  functions.printMatrix(matrixB);
  cout << endl;

  cout << "New Matrix B and Transposed Matrix C Multiplied:" << endl;
  functions.multMatrices(matrixB, matrixC, result);
  functions.printMatrix(result);
  cout << endl;
  
  cout << "Result of Multiplication Added to Matrix A for Solution D:" << endl;
  functions.addMatrices(matrixA, result, matrixD);
  functions.printMatrix(matrixD);
  
  return 0;
}
