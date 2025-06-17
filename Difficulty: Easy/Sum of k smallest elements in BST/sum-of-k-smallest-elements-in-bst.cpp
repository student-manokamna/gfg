// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1

void call (Node* root, int k, int &count, int &sums){
    if(!root)
    return;
    call(root->left, k, count, sums);
    count++;
    if(count<=k){
     
    sums+=root->data;   
    }
    
      call(root->right, k, count, sums);
}

int sum(Node* root, int k) {

    // Your code here
    int count=0;
    int sums=0;
    call(root, k, count, sums);
    return sums;
     
}