// https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;
        int n = intervals.size();
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]) {
            out.push_back(intervals[i]);
            i++;
        }
        int start, end; 
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);      
            i++;
        }
        out.push_back(newInterval);

        while(i < n) {
            out.push_back(intervals[i]);
            i++;
        }
        return out;
    }
};