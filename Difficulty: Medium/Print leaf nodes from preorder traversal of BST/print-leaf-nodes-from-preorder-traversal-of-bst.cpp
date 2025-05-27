class Solution {
  public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
    };

    Node* buildtree(vector<int>& preorder, int& index, int minval, int maxval) {
        if (index >= preorder.size())
            return NULL;

        int key = preorder[index];
        if (key < minval || key > maxval)
            return NULL;

        Node* root = new Node(key);
        index++;

        root->left = buildtree(preorder, index, minval, key - 1); 
        root->right = buildtree(preorder, index, key + 1, maxval);
        return root;
    }

    void leafnode(Node* root, vector<int>& ans) {
        if (!root)
            return;
        if (!root->left && !root->right)
            ans.push_back(root->data);

        leafnode(root->left, ans);
        leafnode(root->right, ans);
    }

    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> ans;
        int index = 0;
        Node* root = buildtree(preorder, index, INT_MIN, INT_MAX);
        leafnode(root, ans);
        return ans;
    }
};
