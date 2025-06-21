// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
       int n = grid.size();
       int m= grid[0].size();
       
           vector<vector<int>> dis(n, vector<int>(m,1e9));
           queue<pair<int, pair<int,int>>> q;
           dis[source.first][source.second]=0;
           q.push({0,{ source.first,source.second}});
           int delrow[]={-1,0,1,0};
           int delcol[]={0,1,0,-1};
           // ✅ Base case if start == end
        if (source == destination) return 0;
           
             while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            //   visit neighbor
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                 int ncol = col+delcol[i];
                 
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1
                 && dist+1<dis[nrow][ncol]){
                     dis[nrow][ncol]=dist+1;
                     if(nrow==destination.first && ncol== destination.second)
                     return dist+1;
                     q.push({dist+1,{nrow, ncol}});
                 }
            }
           }
           return -1;
        
    }
};
