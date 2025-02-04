// https://leetcode.com/problems/top-k-frequent-elements/description/

using P = pair<int, int>;
struct compare
{
    bool operator() (P a, P b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;
        priority_queue<P, vector<P>, compare> pq(mp.begin(), mp.end());
        vector<int> out;
        for(int i = 0; i < k; i++)
        {
            out.push_back(pq.top().first);
            pq.pop();
        }
        return out;
    }
};