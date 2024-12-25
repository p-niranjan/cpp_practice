// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin()+k);
        for(int i = k; i < arr.size(); i++)
        {
            if(arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        vector<int> out;
        while(!pq.empty()) {
            out.push_back(pq.top());
            pq.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
};