using namespace std;

int levenshteinDistance(string str1, string str2) {
  const int N1 = str1.length();
  const int N2 = str2.length();
  vector<int> cols(N1+1);
  vector<vector<int>> edits(N2+1, vector<int>(N1+1,0));
  for(int i=0; i<N2+1; i++) {
    for(int j=0; j<N1+1; j++) {
      edits[i][j] = j;
    }
    edits[i][0] = i;
  }
  for(int i=1; i<N2+1; i++) {
    for(int j=1; j<N1+1; j++) {
      if(str2[i-1] == str1[j-1]) {
        edits[i][j] = edits[i-1][j-1];      
      } else {
        edits[i][j] = 1 + min(edits[i-1][j-1], min(edits[i-1][j], edits[i][j-1]));
      }
    }
  }
  return edits[N2][N1];
}
