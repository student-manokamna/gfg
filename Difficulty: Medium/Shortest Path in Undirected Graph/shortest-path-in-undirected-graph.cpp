class Solution {
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& edges, int src) {
        
        // Build the adjacency list
    int n= edges.size();
        
        queue<int> q;
        vector<int> dis(n, 1e9); // Initialize distances to a large value
        dis[src] = 0; // Distance to source is 0
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Visit neighbors
            for (auto it : edges[node]) {
                if (dis[node] + 1 < dis[it]) { // If a shorter path is found
                    dis[it] = dis[node] + 1;
                    q.push(it);
                }
            }
        }
        
        // Prepare the answer
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (dis[i] == 1e9)
                ans[i] = -1; // Node is unreachable
            else
                ans[i] = dis[i]; // Shortest distance
        }
        
        return ans;
    }
};
