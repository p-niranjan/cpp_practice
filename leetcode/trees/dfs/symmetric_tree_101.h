//https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    bool helper(TreeNode* left, TreeNode* right) {
        if(left && right) {
            if(left->val == right->val) {
                return helper(left->right, right->left) &&
                       helper(left->left, right->right);
            }
        }        
        return left == right;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->right, root->left);
    }
};
