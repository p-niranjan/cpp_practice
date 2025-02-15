// https://leetcode.com/problems/path-sum-iii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int runningSum = 0, cnt = 0;
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1;
        return helper(root, runningSum, targetSum, prefixSums);
    }

    int helper(TreeNode* node, long long runningSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if(nullptr == node) return 0;
        runningSum += node->val;        
        int cnt = prefixSums[runningSum - targetSum];
        prefixSums[runningSum]++;
        cnt += helper(node->left, runningSum, targetSum, prefixSums);
        cnt += helper(node->right, runningSum, targetSum, prefixSums);
        prefixSums[runningSum]--;
        if(0 == prefixSums[runningSum]) prefixSums.erase(runningSum);
        return cnt;
    }
};