/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  
  void search(Node*root, int k , int &ans){
      if(!root)
      return;
      
      if(root->data<=k){
          ans= root->data;
          search(root->right, k,ans);
     }
     else
     search(root->left, k ,ans);
  }
    
    int findMaxFork(Node* root, int k) {
        // code here
       int ans =-1;
       search(root, k , ans);
       return ans ;
    }
};