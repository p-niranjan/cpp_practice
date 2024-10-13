#include <vector>
using namespace std;

using cells = vector<string>;
vector<char> longestCommonSubsequence(string str1, string str2) {
  const int M = str1.size();
  const int N = str2.size();
  cells cols(N+1, "");
  vector<cells> lcs(M+1, cols);
  printf("str1 = %s, M = %d, str2 = %s, N = %d\n", str1.c_str(), M, str2.c_str(), N);
  for(int i = 1; i < M+1; i++) {
    for(int j = 1; j < N+1; j++) {
      printf(" i = %d, j = %d, str1[i-1] = %c, str2[j-1] = %c\n", i, j, str1[i-1], str2[j-1]);
      if(str1[i-1] == str2[j-1]) {
        string copy = lcs[i-1][j-1];
        copy += str1[i-1];
        lcs[i][j] = copy;
        printf("   equal case. lcs[i-1][j-1] = %s, copy = %s, lcs[i][j] = %s\n", lcs[i-1][j-1].c_str(), copy.c_str(), lcs[i][j].c_str());
      } else {
        lcs[i][j] = (lcs[i][j-1].size() > lcs[i-1][j].size()) ? 
                     lcs[i][j-1] : lcs[i-1][j];
        printf("   unequal case. lcs[i][j-1] = %s, lcs[i-1][j] = %s, lcs[i][j] = %s\n", lcs[i][j-1].c_str(), lcs[i-1][j].c_str(), lcs[i][j].c_str());
      }
    }
  }
 printf("final output: %s\n", lcs[M][N].c_str());
 std::vector<char> out(lcs[M][N].begin(), lcs[M][N].end());
 return out; 
}
 