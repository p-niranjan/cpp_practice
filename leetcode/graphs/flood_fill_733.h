// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    using grid = vector<vector<int>>;
    using cell = vector<int>;
    void bfs(int row, int col, grid image, int init, int color, grid& out, grid& vis)
    {
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        grid out = image;        
        int init = image[sr][sc];
        out[sr][sc] = color;
        int m = image.size(), n = image[0].size();
        grid vis(m, vector<int>(n, 0));
        if(init != color) {
            queue<cell> q;
            q.push({sr, sc});
            vis[sr][sc] = 1;
            cell deltaRows = {-1, 0, 1, 0};
            cell deltaCols = {0, 1, 0, -1};
            while(!q.empty()) {
                cell p = q.front();
                q.pop();
                int r = p[0], c = p[1];
                for(int i = 0; i < 4; i++) {
                    int nr = r + deltaRows[i], nc = c + deltaCols[i];
                    if(nr >= 0 && nr < m 
                    && nc >= 0 && nc < n
                    && out[nr][nc] == init
                    && vis[nr][nc] == 0) {
                        q.push({nr, nc});
                        out[nr][nc] = color;
                        vis[nr][nc] = 1;
                    }
                }            
            }
        }
        return out;
    }
};