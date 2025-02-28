//https://leetcode.com/problems/diameter-of-binary-tree/description/

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
// int dia = 0;
class Solution {
public:
    int dfs(TreeNode* node, int& dia)
    {
        if(nullptr == node) return 0;
        int leftHt = dfs(node->left, dia);
        int rightHt = dfs(node->right, dia);
        dia = max(dia, leftHt + rightHt);
        return 1 + max(leftHt, rightHt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        dfs(root, dia);
        return dia;
    }
};
