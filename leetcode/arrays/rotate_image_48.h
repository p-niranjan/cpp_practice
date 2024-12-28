// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void transpose(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> transpose(n, vector<int>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                    transpose[i][j] = matrix[j][i];
                }
            }
        }
        matrix = transpose;
    }
    void print(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            cout << endl;
        }
    }
    void rotate(vector<vector<int>>& matrix) {        
        // print(matrix);        
        reverse(matrix.begin(), matrix.end());
        transpose(matrix);
    }
};