// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> out;
        queue<TreeNode*> q;
        q.push(root);
        // out.push_back({root->val});
        while(!q.empty())
        {
            const int levelSize = q.size();
            vector<int> levelNodes;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                levelNodes.push_back(node->val);
            }            
            if(0 != levelNodes.size()) out.push_back(levelNodes);
        }
        return out;
    }
};