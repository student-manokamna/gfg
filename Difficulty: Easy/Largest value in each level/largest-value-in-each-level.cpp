// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
       queue<Node*>q;
       q.push(root);
       vector<int>ans;
       while(!q.empty()){
           int maxi=0;
           int s= q.size();
           while(s--){
               Node*temp=q.front();
               q.pop();
               maxi= max(maxi, temp->data);
            
               if(temp->left){
                   q.push(temp->left);
               }
                if(temp->right){
                   q.push(temp->right);
               }
               
           }
              ans.push_back(maxi);
       }
       return ans;
        
    }
};