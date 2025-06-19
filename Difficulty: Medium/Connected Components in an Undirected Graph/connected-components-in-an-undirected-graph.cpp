
class Solution {
  public:
  void dfs(vector<int>&ans, vector<int>&vis, int start,vector<vector<int>>&adj){
      vis[start]=1;
      ans.push_back(start);
      for(auto it: adj[start]){
          if(!vis[it])
          dfs(ans, vis, it,adj);
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        //  matrix to list
           vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u); 
}
      
        vector<vector<int>> res;
       int x= adj.size();
        vector<int>vis(x);
        for(int i=0;i<x;i++){
            if(!vis[i]){
                  vector<int>ans;
                dfs(ans, vis, i,adj );
                res.push_back(ans);
            }
        }
        return res;
    }
};
