// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, er = m-1, sc = 0, ec = n-1;
        vector<int> out;
        while(sr <= er && sc <= ec)
        {
            for(int i = sc; i <= ec; i++) out.push_back(matrix[sr][i]);
            for(int i = sr+1; i <= er; i++) out.push_back(matrix[i][ec]);
            for(int i = ec-1; i >= sc; i--) {
                if(sr == er) break;
                out.push_back(matrix[er][i]);
            }
            for(int i = er-1; i > sr; i--) {
                if(sc == ec) break;
                out.push_back(matrix[i][sc]);
            }
            sr++;
            er--;
            sc++;
            ec--;
        }
        return out;
    }
};