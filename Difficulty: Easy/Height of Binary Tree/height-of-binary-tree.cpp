/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int h=INT_MIN;
  void hei(Node*root, int h1 ){
      if(!root)
      return ;
      h= max(h, h1);
          h1++;
      hei(root->left, h1);
      hei(root->right, h1);
  }
    int height(Node* node) {
        // code here
        int count=0;
        int h1=0;
        hei(node, h1);
        return h;
    }
};