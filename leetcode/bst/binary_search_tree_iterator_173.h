//https://leetcode.com/problems/binary-search-tree-iterator/description/

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
#include <stack>

class BSTIterator {
private:
    stack<TreeNode*> stk;

    void pushAll(TreeNode* node) {
        while(node)
        {
            stk.push(node);
            node = node->left;
        }        

    }
public:
    BSTIterator(TreeNode* root) {
        // if(root->left) {
        pushAll(root);
        // }        
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
