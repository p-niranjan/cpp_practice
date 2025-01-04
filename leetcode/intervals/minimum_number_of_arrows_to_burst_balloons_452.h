// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

struct compare
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare());
        int arrows = 1;
        int lastEnd = points[0][1];
        for(int i = 0; i < points.size(); i++)
        {
            vector<int> cur = points[i];
            if(cur[0] > lastEnd) {
                arrows++;
                lastEnd = cur[1];
            }
        }
        return arrows;
    }
};