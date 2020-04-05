/*
Rotate Matrix 1.7
Write a method to rotate a matrix by 90 degrees
Tranpose a matrix
*/
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<vector<int>> rotateMatrix(T& matrix){
  size_t n = matrix[0].size();
  vector<vector<int>> newMatrix(n,vector<int>(n,1));

  for(int i = 0; i < matrix.size(); ++i){
    for(int j = 0; j < matrix[i].size(); ++j){
      newMatrix[j][i] = matrix[i][j];
    }
  }
  return newMatrix;
}
/*
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
*/
template <typename T>
void printVec(const T& matrix){
  for(auto vec : matrix){
    for(int n : vec) cout << n << " ";
    cout << endl;
  }
}
int main() {
  vector<vector<int>> matrix{
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12},
  {13,14,15,16}
  };
  printVec(matrix);
  cout << "-------------------" << endl;
  matrix = rotateMatrix(matrix);
  printVec(matrix);
}