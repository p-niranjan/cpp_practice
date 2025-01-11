// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    using cell = pair<int, int>;
    using P = pair<cell,int>;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<P> q;        
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int time = 0;
        vector<int> deltaRows = {-1, 0 , 1, 0};
        vector<int> deltaCols = {0 , 1, 0, -1};
        while(!q.empty())
        {
            P p = q.front();
            q.pop();
            int row = p.first.first, col = p.first.second;
            int tm = p.second;
            time = max(tm, time);
            for(int d = 0; d < 4; d++)
            {
                int nrow = row + deltaRows[d];
                int ncol = col + deltaCols[d];
                if(nrow >= 0 && nrow < m
                && ncol >= 0 && ncol < n
                && grid[nrow][ncol] == 1
                && vis[nrow][ncol] != 2) {
                    q.push({{nrow, ncol}, tm + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2) 
                    return -1;
            }
        }

        return time;
    }
};