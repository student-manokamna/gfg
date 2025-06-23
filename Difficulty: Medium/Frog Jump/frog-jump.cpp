class Solution {
public:
//  m-3 using o(1) space means now it is after tabular to -> space optimisation


    int minCost(vector<int>& height) {
        int n = height.size();
          int prev2=0;
          int prev=0;
              for(int i=1;i<n;i++){
                   int left = prev+ abs(height[i] - height[i - 1]);

        int right = INT_MAX; // bcz when we have f(1) then left is defined as f(0) but no right na 
        if (i > 1)
            right = prev2 + abs(height[i] - height[i - 2]);
int curr= min(left, right);
prev2=prev;
prev=curr;
              }
            
      return prev;
    }
};

//  bs esme dp bnao -> fir ager dp[i] -1 nhi toh return it ->  and then store min in dp[i] na
