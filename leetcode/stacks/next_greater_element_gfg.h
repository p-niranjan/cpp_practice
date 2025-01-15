// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> out(n);
        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty() && arr[i] >= stk.top()) stk.pop();
            if(stk.empty()) out[i] = -1;
            else out[i] = stk.top();
            stk.push(arr[i]);
        }
        return out;
    }
};