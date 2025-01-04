// https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

using event = pair<int, int>;
struct compare
{
    bool operator()(event a, event b)
    {
        if(a.first == b.first)
            return a.second < b.second;
            
        return a.first < b.first;
    }
};

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        vector<event> rooms;
        int n = start.size();
        for(int i = 0; i < n; i++)
        {
            rooms.push_back({start[i], 1});
            rooms.push_back({end[i], -1});
        }
        sort(rooms.begin(), rooms.end(), compare());
        int numberOfRooms = 0, maxRooms = 0;
        for(auto room : rooms)
        {
            numberOfRooms += room.second;
            maxRooms = max(maxRooms, numberOfRooms);
        }
        return maxRooms;
    }
};