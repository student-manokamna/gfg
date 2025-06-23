class Solution {
public:
//  m-2 now using dp we do -> tabular m  as it is done after meorisation  
//    as here in tabular we do -> definne dp then first we deal with base cases 
//   base cases meanns we satrt fom here then we do recursiove calls
//  and here we defne by dp[]... 

    int minCost(vector<int>& height) {
        int n = height.size();
          vector<int>dp(n,-1);
              dp[0]=0;
              for(int i=1;i<n;i++){
                   int left = dp[i-1]+ abs(height[i] - height[i - 1]);

        int right = INT_MAX; // bcz when we have f(1) then left is defined as f(0) but no right na 
        if (i > 1)
            right = dp[i-2] + abs(height[i] - height[i - 2]);

dp[i]= min(left, right);
              }
            
      return dp[n-1];
    }
};

//  bs esme dp bnao -> fir ager dp[i] -1 nhi toh return it ->  and then store min in dp[i] na
