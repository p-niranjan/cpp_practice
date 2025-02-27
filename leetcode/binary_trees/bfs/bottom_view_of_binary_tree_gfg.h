//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

using TreeNode = pair<Node*, int>;

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(!root) return {};
        map<int, int> mp;
        queue<TreeNode> q;
        q.push({root, 0});
        while(!q.empty()) {
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();
            mp[line] = node->data;
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        vector<int> out;
        for(auto p : mp) {
            out.push_back(p.second);
        }
        return out;
    }
};
