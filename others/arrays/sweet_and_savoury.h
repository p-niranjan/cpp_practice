using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) {
  vector<int> sweet;
  vector<int> savory;
  vector<int> bestPair{0,0};
  int N = dishes.size();
  for(int i=0; i<N; i++) {
    if(dishes[i] < 0) {
      sweet.push_back(dishes[i]);
    } else {
      savory.push_back(dishes[i]);
    }
  }

  sort(savory.begin(), savory.end());
  sort(sweet.begin(), sweet.end(), [](int a, int b) {
    return abs(a) < abs(b);
  });
  int i = 0, j = 0;
  while(i < sweet.size() && j < savory.size()) {
    int bestDiff = INT_MAX;    
    int sum = sweet[i] + savory[j];
    if(sum <= target) {
      int curdiff = target - sum;
      if(curdiff < bestDiff) {
        bestDiff = curdiff;
        bestPair[0] = sweet[i];
        bestPair[1] = savory[j];
      }
      j++;
    } else {
      i++;
    }
  }
  return bestPair;
}
