// https://leetcode.com/problems/car-pooling/description/
using event = pair<int, int>;

struct compare
{
    bool operator()(event e1, event e2)
    {
        if(e1.first == e2.first) 
            return e1.second < e2.second;
        return e1.first < e2.first;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<event> events;
        for(auto trip : trips)
        {
            events.emplace_back(trip[1], trip[0]);
            events.emplace_back(trip[2], -trip[0]);
        }
        sort(events.begin(), events.end(), compare());
        int currentPassengers = 0;
        for(auto ev : events)
        {
            currentPassengers += ev.second;
            if(currentPassengers > capacity)
                return false;
        }
        return true;
    }
};