// https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/

using pr = pair<int, int>;

struct compare {
    bool operator()(pr p1, pr p2)
    {
        if(p1.second == p2.second) 
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};
    
class Solution {
  public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++) mp[arr[i]]++;
        
        priority_queue<pr, vector<pr>, compare> minHeap(mp.begin(), mp.end());
        vector<int> out;
        for(int i = 0; i < k; i++) {
            out.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return out;
    }
};
