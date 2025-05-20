//https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if('1' == grid[i][j] && 0 == vis[i][j]) {
                    dfs(i, j, vis, grid);
                    cnt++;
                }                
            }
        }
        return cnt;
    }

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[row][col] = 1;
        int m = grid.size(), n = grid[0].size();
        vector<int> drow{-1, 0, 1, 0}, dcol{0, -1, 0, 1};
        for(int d = 0; d < 4; d++) {
            int nr = row + drow[d], nc = col + dcol[d];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               '1' == grid[nr][nc] && 0 == vis[nr][nc]) {
                dfs(nr, nc, vis, grid);
            }
        }
    }
};