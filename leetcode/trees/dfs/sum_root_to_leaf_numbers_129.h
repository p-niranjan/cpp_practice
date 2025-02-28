// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    void sumNumbersHelper(TreeNode* node, int num, int level, int& sum) {
        if(nullptr == node) return;
        num = num*10 + node->val; 
        if(!node->left && !node->right) {            
            sum += num;
        }
        sumNumbersHelper(node->left, num, level+1, sum);
        sumNumbersHelper(node->right, num, level+1, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;
        sumNumbersHelper(root, num, 0, sum);
        return sum;
    }
};