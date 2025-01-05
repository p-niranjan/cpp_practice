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
 using path = vector<int>;
class Solution {
public:
    void pathSumHelper(TreeNode* node, int runningSum, const int& targetSum, path& p, vector<path>& out) {
        if(nullptr == node) return;
        
        p.push_back(node->val);
        runningSum += node->val;
        
        if(!node->left && !node->right) {
            if(runningSum == targetSum) {
                out.push_back(p);
            }
        }
        pathSumHelper(node->left, runningSum, targetSum, p, out);
        pathSumHelper(node->right, runningSum, targetSum, p, out);
        
        p.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> out;
        path p;
        pathSumHelper(root, 0, targetSum, p, out);
        return out;
    }
};