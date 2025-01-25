// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        // return isSubsetSumHelperRecursion(n-1, arr, target);
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        dp[0][arr[0]] = true;
        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                int ntk = dp[i-1][j];
                int tk = false;
                if(j >= arr[i])
                    tk = dp[i-1][j-arr[i]];
                dp[i][j] = tk || ntk;
            }
        }
        return dp[n-1][target];
    }
    
    bool isSubsetSumHelperRecursion(int idx, vector<int>& arr, int target) {
        if(idx == 0) return arr[0] == target;
        if(target == 0) return true;
        
        int ntk = isSubsetSumHelperRecursion(idx-1, arr, target);
        int tk = false;
        if(target >= arr[idx]) 
            tk = isSubsetSumHelperRecursion(idx-1, arr, target-arr[idx]);
        
        return tk || ntk;
    }
};