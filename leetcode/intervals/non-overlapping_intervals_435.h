// https://leetcode.com/problems/non-overlapping-intervals/description/?envType=study-plan-v2&envId=leetcode-75

using interval = vector<int>;
struct compare
{
    bool operator()(interval a, interval b)
    {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare());
        int prev = 0, count = 1, n = intervals.size();
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] >= intervals[prev][1]) {
                count++;
                prev = i;
            }
        }
        return n - count;
    }
};