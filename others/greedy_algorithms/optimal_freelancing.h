using namespace std;

bool compare(unordered_map<string, int> m1, unordered_map<string, int> m2) 
{
  return (m1["payment"] > m2["payment"]);
}

int optimalFreelancing(vector<unordered_map<string, int>> jobs) {
  sort(jobs.begin(), jobs.end(), compare);
  int profit = 0;
  vector<bool> timeline(7, false);
  for(auto job : jobs) {
    int maxTime = min(job["deadline"], 7);
    for(int i=maxTime; i>0; i--) {
      if(timeline[i] == false) {
        timeline[i] = true;
        profit += job["payment"];
        break;
      }
    }
  }
  return profit;
}
