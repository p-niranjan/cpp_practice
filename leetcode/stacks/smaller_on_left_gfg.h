// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        stack<int> stk;
        vector<int> out(n, -1);
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && stk.top() >= arr[i]) stk.pop();
            if(!stk.empty()) out[i] = stk.top();
            stk.push(arr[i]);
        }
        return out;
    }
};