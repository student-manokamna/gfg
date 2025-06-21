// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
 vector<pair<int, int>> adj[V]; // node → {{adjNode, weight}, ...}
for (auto &e : edges) {
    int u = e[0];
    int v = e[1];
    int wt = e[2];
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt}); // only if graph is undirected
}
    vector<int>dis(V);
    for(int i=0;i<V;i++) dis[i]=1e9;
    dis[src]=0;
    pq.push({0,src});
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node =pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int nod= it.first;
            int wt = it.second;
            if(dist+wt<dis[nod]){
                dis[nod]= dist+wt;
                pq.push({dis[nod], nod});
            }
        }
    }
    vector<int>ans(V);
    for(int i =0;i<V;i++){
        if(dis[i]!=1e9)
        ans[i]=dis[i];
    }
    return ans;

    }
};