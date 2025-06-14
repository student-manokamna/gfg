/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
  
  bool ismirror(Node*n1, Node*n2){
        if(!n1&& !n2)
        return true;
        
        if(n1&& !n2 || !n1 && n2)
          return false;
          
          if(n1->data!= n2->data)
            return false;
        
          return ismirror(n1->left, n2->right) && ismirror(n1->right, n2->left);
          
  }
    bool isSymmetric(Node* root) {
  return ismirror(root->left, root->right);
  
        

    }
};