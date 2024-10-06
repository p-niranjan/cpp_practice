using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  // Write your code here.
  const int targetRows = matrix[0].size();
  const int targetColumns = matrix.size();
  vector<int> col(targetColumns);
  vector<vector<int>> targetMatrix(targetRows, col);
  for(int i=0; i<matrix.size(); i++) {
    for(int j=0; j<matrix[i].size(); j++) {
      if(i != j) {
        targetMatrix[j][i] = matrix[i][j];
      } else {
        targetMatrix[j][i] = matrix[j][i];
      }
    }
  }
  return targetMatrix;
}
