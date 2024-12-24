#include <vector>
#include <unordered_map>
using namespace std;

#define HOME 1
#define AWAY 0

string tournamentWinner(
  vector<vector<string>> competitions, vector<int> results) {
  // Write your code here.
  string win = "", cur = "";
  unordered_map<string,int> out;
  for(int i = 0; i < competitions.size(); i++) {
    int winIndex = (results[i] == 0) ? HOME : AWAY;
    cur = competitions[i][winIndex];
    out[cur] += 3;    
    win = (out[cur] > out[win]) ? cur : win;
    cout << "i: " << i << " winIndex: " << winIndex << " cur: " << cur << " out[cur]: " << out[cur] << " win: " << win << " out[win]: " << out[win] << endl;
  }
  return win;
}
