class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        //  make priority queue
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    //  create a visited arr;
    vector<int>vis(V,0);
    //  only calc sum so need   {weight, node};
    //  intially both r zero na as wt is zero and start with 0 node
    
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        int wt= pq.top().first;
        int node= pq.top().second;
        pq.pop();
        //  ager mera node vis hh already no need to ove further and goes to child just stop there
        
        if(vis[node]==1) continue;
        //  not vis then vis and add wt to mst 
        vis[node]=1;
        sum+=wt;
        //  if not vis then move to neighbor
        for(auto it: adj[node]){
            int adjnode= it[0];
            int edwt= it[1];
            if(!vis[adjnode])
            pq.push({edwt, adjnode});
        }
    }
    return sum;
        
    }
};