class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code hezre
        vector<pair<int,int>> adj[n+1];
        for(auto e: edges){
            int u= e[0];
            int v = e[1];
            int w =e[2];
            adj[u].push_back({v,w});
               adj[v].push_back({u,w});
            
        }
            vector<int>dis(n+1,1e9);  // we want 1-based indexing
            vector<int>parent(n+1);
            for(int i=0;i<n;i++){
                dis[i]=1e9;
            }
             for(int i=0;i<n;i++){
              parent[i]=i;
            }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
       dis[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int dist= pq.top().first;
            int nod = pq.top().second;
            pq.pop();
            for(auto it: adj[nod]){
                int fis = it.first;
                int sec= it.second;
                if(dist+sec<dis[fis]){
                    dis[fis]=dist+sec;
                    parent[fis]=nod;
                    pq.push({dis[fis],fis});
                }
            }
        }
        vector<int>patharr;
        if(dis[n]==1e9)
        return {-1};
        int node= n;
        while(parent[node]!=node){
            patharr.push_back(node);
            node=parent[node];
        }
        patharr.push_back(1); // last vala elm daalna hh 
        reverse(patharr.begin(),patharr.end());
                patharr.insert(patharr.begin(), dis[n]);

      return patharr;  
    }
};