class Solution {
  public:
  int func(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
    //    base case
    if(day==0){
        //  go over all task
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){  // means ager jo task le rhi hu repeat nhi ho rha last vala hoi
                maxi= max(maxi, arr[0][task]); // it is arr[day][task] but it is base case
                                           //  so where day=0 na
            }
        }
        return maxi;
    }
    //  now recursive calls
    if(dp[day][last]!=-1)
    return dp[day][last];
    int maxi=0;
    for(int task=0;task<3;task++){
       if(task!=last){
           int point = arr[day][task]+ func(day-1, task, arr,dp);  // as current point add fir 
        //    pichle day ko bolo bhai jo mainr task liya hh vo toh mt lena 
        maxi= max(maxi, point);
       }
    }
    return dp[day][last]= maxi;
    
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        //  as last se start so n-1 , not tsk touched till noe so pass3 
        int n= arr.size();
        vector<vector<int>> dp(n, vector<int>(4,-1)); // as size of dp is n*4 as 
        //  day is n while col is 4 as 0,1,2,3 -> for performing task 
       return  func(n-1,3,arr,dp);
    }
};