// https://leetcode.com/problems/binary-tree-paths/
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
    void binaryTreePathsHelper(TreeNode* node, string path, vector<string>& out) {
        if(nullptr == node) return;
        path += to_string(node->val) + "->";
        if(!node->left && !node->right) {
            path.pop_back();
            path.pop_back();
            out.push_back(path);
        }
        binaryTreePathsHelper(node->left, path, out);
        binaryTreePathsHelper(node->right, path, out);
    } 
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> out;
        string path;
        binaryTreePathsHelper(root, path, out);
        return out;
    }
};