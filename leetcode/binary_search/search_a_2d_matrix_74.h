//https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while(i < m && j >= 0) {
            if(matrix[i][j] < target) i++;
            else if(matrix[i][j] > target) j--;
            else return true;
        }
        return false;
    }
};
