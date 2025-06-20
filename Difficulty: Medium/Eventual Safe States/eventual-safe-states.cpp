// User function Template for C++

class Solution {
  public:
        bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& path, vector<int>& check)
    {
        vis[node] = 1;
        path[node] = 1;
    
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj, vis, path, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else 
            {
                if(path[it] == 1)
                {
                     check[node] = 0;
                     return true;
                }
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }
  
  
  
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) 
    {
        vector<int> vis(v,0);
        vector<int> path(v,0);
        vector<int> check(v,0);
        vector<int> ans;
    
        for(int i = 0; i<v ;i++)
        {
            if(!vis[i])
            {
                bool a = dfs(i, adj, vis, path, check);
            }
        }
        for(int i = 0; i<v ;i++)
        {
            if(check[i] == 1)
            {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
