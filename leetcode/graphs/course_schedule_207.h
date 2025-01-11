// https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjL(V);
        for(auto prrq : prerequisites) 
            adjL[prrq[1]].push_back(prrq[0]);
        
        vector<int> indegree(V, 0);
        for(int v = 0; v < V; v++) {
            for(int w : adjL[v]) indegree[w]++;
        }
        queue<int> q;
        for(int v = 0; v < V; v++) {
            if(0 == indegree[v]) q.push(v);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int adj : adjL[node]) {
                indegree[adj]--;
                if(0 == indegree[adj]) q.push(adj);
            }
        }
        return topo.size() == V;
    }
};