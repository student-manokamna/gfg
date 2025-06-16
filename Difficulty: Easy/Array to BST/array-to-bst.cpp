/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
  
  Node*arrange(int start, int end,vector<int>& nums ){
    if(start>end)
    return NULL;
    
      int n=nums.size();
      int mid = start+(end-start)/2;
       Node*root = new Node(nums[mid]);
      root->left =arrange(start, mid-1, nums);
      root->right = arrange(mid+1, end, nums);
      return root;
      
  }
  
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
     
        int n= nums.size();
        Node*root= arrange(0,n-1, nums);
        
        
        
        return root;
    }
};