// https://leetcode.com/problems/path-sum/description/

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
    bool hasPathSumHelper(TreeNode* node, int runningSum, int targetSum) {
        if(nullptr == node) return false;
        runningSum += node->val;
        if(!node->left && !node->right) return targetSum == runningSum;        
        printf("runningSum = %d, node->val = %d\n", runningSum, node->val);
        return hasPathSumHelper(node->left, runningSum, targetSum) || 
            hasPathSumHelper(node->right, runningSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int runningSum = 0;
        return hasPathSumHelper(root, runningSum, targetSum);
    }
};