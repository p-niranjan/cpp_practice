// https://www.geeksforgeeks.org/problems/attend-all-meetings/1

using P = vector<int>;
struct compare
{
    bool operator()(P p1, P p2)
    {
        return p1[0] < p2[0];
    }
};

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end(), compare());
        for(int i = 0; i < arr.size()-1; i++)
        {
            P cur = arr[i];
            P next = arr[i+1];
            if(next[0] < cur[1]) return false;
        }
        return true;
    }
};