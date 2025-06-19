class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
    queue<int>q;
    q.push(0);
    int vis[n]={0};
    vis[0]=1;
    vector<int>ans;
    
    while(!q.empty()){
        int fornt= q.front();
        q.pop();
        ans.push_back(fornt);
        for(auto it: adj[fornt]){
           if(!vis[it]){
               vis[it]=1;
               q.push(it);
           }   
        }
        
    }
    
      return ans; 
        
    }
};