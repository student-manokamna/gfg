// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>adjrev[V];
        vector<int>indeg(V,0);
        for(int i=0;i<V;i++){
            // neighbor->i  as i want in reverse order na 
            for(auto it: adj[i]){
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            //  visit neighbor
            for(auto it:adjrev[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
