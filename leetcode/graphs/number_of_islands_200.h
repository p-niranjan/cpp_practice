// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    using pair = vector<int>;
    void bfs(int row, int col, vector<pair>& vis, int cnt, vector<vector<char>>& grid)
    {
        queue<pair> q;
        q.push({row, col});
        vis[row][col] = 1;
        vector<int> deltaRows = {-1, 0, 1, 0};
        vector<int> deltaCols = {0, 1, 0, -1};
        int m = grid.size(), n = grid[0].size();
        while(!q.empty())
        {
            pair p = q.front();
            q.pop();
            int r = p[0], c = p[1];
            for(int dr = 0; dr < 4; dr++) {                
                int nr = r + deltaRows[dr], nc = c + deltaCols[dr];
                if(nr >= 0 && nr < m &&
                    nc >= 0 && nc < n && 
                    grid[nr][nc] == '1' &&
                    vis[nr][nc] == 0) 
                {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<pair> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cnt++;
                    bfs(i, j, vis, cnt, grid);
                }
            }            
        }
        return cnt;
    }
};