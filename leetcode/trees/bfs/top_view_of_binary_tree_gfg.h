//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/

struct TreeNode {
    Node* node;
    int line;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        if(!root) return {};
        
        queue<TreeNode> q;
        q.push({root, 0});
        map<int, int> mp;
        while(!q.empty()) {
            int line = q.front().line;
            Node* node = q.front().node;
            q.pop();
            if(mp.find(line) == mp.end()) 
                mp[line] = node->data;
            
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        vector<int> out;
        for(auto lineValues : mp) {
            out.push_back(lineValues.second);
        }
        return out;
    }
};
