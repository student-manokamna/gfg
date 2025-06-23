class Solution {
public:
    int fn(int idx , vector<int>& arr, vector<int>& dp){
        // base case
        if (idx == 0)
            return arr[0];
        if (idx < 0)
            return 0;

        // memo check
        if (dp[idx] != -1)
            return dp[idx];

        // pick current element and skip previous
        int pick = arr[idx] + fn(idx - 2, arr, dp);

        // do not pick current, move to previous index
        int not_pick = fn(idx - 1, arr, dp);

        return dp[idx] = max(pick, not_pick);
    }

    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return fn(n - 1, arr, dp);
    }
};
