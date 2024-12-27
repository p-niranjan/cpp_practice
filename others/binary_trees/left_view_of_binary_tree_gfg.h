// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        if(!root) return {};
        vector<int> out;
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            const int size = q.size();
            Node* node = nullptr;
            for(int i = 0; i < size; i++)
            {
                node = q.front();
                q.pop();
                if(0 == i) out.push_back(node->data); 
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return out;
    }
};