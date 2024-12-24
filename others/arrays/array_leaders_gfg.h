// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?itm_source=geeksforgeeks

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size(), maxi = arr[n-1];
        vector<int> out;
        out.push_back(arr[n-1]);
        for(int i = n-2; i >= 0; i--)
        {
            if(arr[i] >= maxi){
                out.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(out.begin(), out.end());
        return out;
    }
};