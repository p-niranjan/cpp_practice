#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> getUnvisitedNeighbours(const vector<vector<int>> &matrix, 
  const vector<vector<bool>> &visited,
  const int &i, const int &j)
{
  vector<vector<int>> uvn;
  const int M = matrix.size();
  const int N = matrix[0].size();
  if(i > 0 && !visited[i-1][j]) {
    uvn.push_back({i-1, j});
  }
  if(i < M-1 && !visited[i+1][j]) {
    uvn.push_back({i+1, j});
  }
  if(j > 0 && !visited[i][j-1]) {
    uvn.push_back({i, j-1});
  }
  if(j < N-1 && !visited[i][j+1]) {
    uvn.push_back({i,j+1});
  }

  return uvn;
}

void traverseNodes(const vector<vector<int>> &matrix,
                   vector<int> &sizes,
                   vector<vector<bool>> &visited, int i, int j)
{
  const int M = matrix.size();
  const int N = matrix[0].size();
  int curRiverSize = 0;
  vector<vector<int>> nodes;
  nodes.push_back({i,j});
  while(nodes.size() != 0) {
    vector<int> pair = nodes.back();
    nodes.pop_back();
    int row = pair[0];
    int col = pair[1];
    if(visited[row][col]) {
      continue;
    }
    visited[row][col] = true;
    if(matrix[row][col] == 0) {
      continue;
    }
    curRiverSize++;
    vector<vector<int>> unvisitedNeighbours = 
      getUnvisitedNeighbours(matrix, visited, row, col);
    for(auto neighbour : unvisitedNeighbours) {
      nodes.push_back(neighbour);
    }
  }
  if(curRiverSize > 0) {
    sizes.push_back(curRiverSize);  
  }
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  const int M = matrix.size();
  const int N = matrix[0].size();
  vector<bool> cols(N, false);
  vector<vector<bool>> visited(M, cols);
  vector<int> sizes;
  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
      if(visited[i][j]) {
        continue;
      }
      traverseNodes(matrix, sizes, visited, i, j);
    }
  }
  return sizes;
}


