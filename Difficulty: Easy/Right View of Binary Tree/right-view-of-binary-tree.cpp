/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    vector<int> rightView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();  // number of nodes at current level
            // int i = 0;

            while (s--) {
                Node* temp = q.front();
                q.pop();
                // i++;

                // If it's the last node of this level
                if (s == 0)
                    ans.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return ans;
    }
};
