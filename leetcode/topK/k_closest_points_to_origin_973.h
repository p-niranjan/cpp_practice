// https://leetcode.com/problems/k-closest-points-to-origin/description/

using point = vector<int>;
using P = pair<point,int>;

class Solution {
public:
    vector<point> kClosest(vector<point>& points, int k) {
       priority_queue<pair<int, point>> pq;
       for(auto p : points)
       {
            int dist = p[0]*p[0] + p[1]*p[1];
            pq.push({dist, p});
            if(pq.size() > k) pq.pop();
       }
       vector<point> out;
       for(int i = 0; i < k; i++)
       {
            out.push_back(pq.top().second);
            pq.pop();
       }
       return out;
    }
};