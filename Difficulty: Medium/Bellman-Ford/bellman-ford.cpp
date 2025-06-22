// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dis(V, 1e8);
        dis[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto e: edges){
                int u= e[0];
                int v= e[1];
                int w =e[2];
                if(dis[u]!=1e8 && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                }
            }
        }
        //  negative cycle
        for(auto e: edges){
                int u= e[0];
                int v= e[1];
                int w =e[2];
                if(dis[u]!=1e8 && dis[u]+w<dis[v]){
                 return {-1};
                }
            }
            return dis;
        
    }
};
