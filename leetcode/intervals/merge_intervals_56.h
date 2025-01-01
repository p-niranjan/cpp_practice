// https://leetcode.com/problems/merge-intervals/description/
using P = vector<int>;
struct compare
{
    bool operator()(P p1, P p2)
    {
        return p1[0] < p2[0];
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<P> out;
        sort(intervals.begin(), intervals.end(), compare());
        out.push_back(intervals[0]);
        int idx = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            P cur = intervals[i];
            P& last = out[idx];
            if(last[1] >= cur[0])
                last[1] = max(last[1], cur[1]);
            else {
                out.push_back(cur);
                idx++;
            } 
        }
        return out;
    }
};