class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
            for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v); // directed edge from u to v
}
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it: adj[i])
        indegree[it]++;
    }
    queue<int>q;
    vector<int>top;
    for(int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            top.push_back(node);
            //  neighbor
            for(auto it: adj[node]){
                indegree[it]--;
                 if(indegree[it]==0)
                q.push(it);
            }
        }
        if(top.size()==V)
        return false;
        return true;
    }
};