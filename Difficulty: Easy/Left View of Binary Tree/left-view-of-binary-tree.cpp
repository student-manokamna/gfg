/* A binary tree node

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
        // code here
            vector<int>ans;
           if (!root) return ans;
    
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s= q.size();
            Node*temp=q.front();
         ans.push_back(temp->data);
         while(s--){
             temp= q.front();
             q.pop();
             if(temp->left)
             q.push(temp->left);
              if(temp->right)
             q.push(temp->right);
         }
        }
        return ans;
    }
};