// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

using event = pair<int, int>;

struct compare
{
    bool operator()(event a, event b)
    {
        if(a.first == b.first) 
            return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        vector<event> trains;
        for(int i = 0; i < n; i++)
        {
            trains.push_back({arr[i], 1});
            trains.push_back({dep[i]+1,-1});
        }
        sort(trains.begin(), trains.end(), compare());
        
        int platforms = 0, maxPlatforms = 0;
        for(event train : trains)
        {
            platforms += train.second;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};