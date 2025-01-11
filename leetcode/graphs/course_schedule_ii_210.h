// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        for(auto prrq : prerequisites) adjL[prrq[1]].push_back(prrq[0]);
        vector<int> indegree(numCourses, 0);
        for(int v = 0; v < numCourses; v++) {
            for(int adj : adjL[v]) {
                indegree[adj]++;
            }
        }
        queue<int> q;
        for(int v = 0; v < numCourses; v++) {
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
        
        return topo.size() == numCourses ? topo : vector<int>();
    }
};