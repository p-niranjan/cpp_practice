// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int V = graph.size();
        vector<vector<int>> adjL(V);
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                adjL[i].push_back(graph[i][j]);
            }
        }
        vector<int> sets(V, -1);
        for(int v = 0; v < V; v++)
        {
            if(-1 == sets[v])
            {
                if(!isBipartiteHelper(v, sets, adjL)) return false;
            }
        }
        return true;
    }

    bool isBipartiteHelper(int node, vector<int> sets, vector<vector<int>> adjL) {
        queue<int> q;
        q.push(node);
        sets[node] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int adj : adjL[node])
            {
                if(sets[adj] == -1) {
                    sets[adj] = !sets[node];
                    q.push(adj);
                } else if(sets[adj] == sets[node]) {
                    return false;
                }
            }
        }
        return true;
    }
};