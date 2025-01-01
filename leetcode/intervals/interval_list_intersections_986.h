// https://leetcode.com/problems/interval-list-intersections/description/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0, m = firstList.size(), n = secondList.size();
        vector<vector<int>> out;
        while(i < m && j < n)
        {
            vector<int> first = firstList[i];
            vector<int> second = secondList[j];
            bool firstOverlapsSecond = first[0] >= second[0] && first[0] <= second[1];
            bool secondOverlapsFirst = second[0] >= first[0] && second[0] <= first[1];

            if(firstOverlapsSecond || secondOverlapsFirst)
            {
                int start = max(first[0], second[0]);
                int end = min(first[1], second[1]);
                out.push_back({start, end});
            }

            if(first[1] < second[1]) i++;
            else j++;
        }
        return out;
    }
};