// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75

using cell = pair<int, int>;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int erow = entrance[0], ecol = entrance[1];
        int steps = 0, m = maze.size(), n = maze[0].size();
        const vector<int> deltaRows{-1, 0, 1, 0};
        const vector<int> deltaCols{0, 1, 0, -1};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<cell> q;        
        q.push({erow, ecol});
        vis[erow][ecol] = 1;
        while(!q.empty())
        {            
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                cell c = q.front();
                q.pop();
                int row = c.first, col = c.second;
                for(int d = 0; d < 4; d++)
                {
                    int drow = row + deltaRows[d], dcol = col + deltaCols[d];                 
                    if(drow >= 0 && drow < m
                    && dcol >= 0 && dcol < n
                    && maze[drow][dcol] == '.'
                    && vis[drow][dcol] == 0) {
                        if(drow == m-1 || dcol == n-1 || drow == 0 || dcol == 0
                        && !(drow == erow && dcol == ecol)) {
                            return steps+1;
                        }
                        q.push({drow, dcol});
                        vis[drow][dcol] = 1;
                    }
                }
            }   
            steps++;
        }
        return -1;
    }
};