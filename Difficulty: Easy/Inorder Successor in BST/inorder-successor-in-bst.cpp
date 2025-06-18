/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
       void  inor(Node *root,  vector<int> &ans ){
           if(!root)
           return;
           inor(root->left, ans);
           ans.push_back(root->data);
           inor(root->right, ans);
           
       } 
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
      vector<int>ans;
      int val = x->data;
      inor(root,ans);
      for(int i=0;i<ans.size()-1;i++){
          if(ans[i]==val)
          return ans[i+1];
      }
        return -1;
    }
};