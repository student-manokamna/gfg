// User function Template for C++
class Solution {
  public:
//    o(n+e)
 void dfs(vector<int> &vis, int start, vector<pair<int,int>> adj[], stack<int>& s){
      vis[start]=1;
      for(auto it: adj[start]){
          if(!vis[it.first])
          dfs(vis, it.first, adj, s);
      }
      s.push(start);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        //  traverse over all edges
        for(int i=0;i<E;i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        vector<int>vis(V,0);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(vis, i, adj,s);
            }
        }
        //  now made a distance arr and then form stack compare all things in that
        vector<int>dist(V);
        for(int i=0;i<V;i++)
        dist[i]= 1e9;
        // now assign source node jaha se start krna hh ye dena hiota hi hh dist m
        // given ho toh thik vrna zero ki source maan lete hh 
        dist[0]=0;
        //  tc for due to stack is n and for neeche jo ayega neighbour vala uski vajah se m
        while(!s.empty()){
            int node= s.top();
            s.pop();
            //  visit its neighbour
            for(auto it: adj[node]){
                //  tou usme v and wt hoga so extratc that 
                int v = it.first;
                int wt= it.second;
                if(dist[node]+wt<dist[v])
                  dist[v]=dist[node]+wt;
            }
        }
           for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
        
    }
};
