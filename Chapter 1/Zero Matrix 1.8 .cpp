/*
Zero Matrix 1.8
Write an algorithm such that if an element in a M * N matrix is 0, its entire row and column are set to 0
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void zeroMatrix(T& matrix){
  int row = -1;
  int column = -1;

  //Identify row,column
  for(int i = 0; i < matrix.size(); ++i){
    for(int j = 0; j < matrix[i].size(); ++j){
      if(matrix[i][j] == 0){
        row = i;
        column = j;
      }
    }
  }
  if(row != -1 && column != -1){
    //Set horizontal to 0
    for(int i = 0; i < matrix[row].size(); ++i)    matrix[row][i] = 0;

    //Set vertical to 0
    for(int i = 0; i < matrix.size();++i){
    matrix[i][column] = 0;
  }
  }
}

template <typename T>
void printMatrix(const T& matrix){
  for(auto outer : matrix){
    for(int n : outer) cout << n << " ";
  cout << endl;
  }
}
/*

[
  [1,2,3],
  [4,0,6],
  [7,8,9]
]
[
  [1,0,3],
  [0,0,0],
  [7,0,9]
]
*/
int main() {
  vector<vector<int>> matrix{
    {1,2,3},
    {0,5,6},
    {7,8,9}
  };

  printMatrix(matrix);
  cout << "----------------" << endl;
  zeroMatrix(matrix);
  printMatrix(matrix);

}