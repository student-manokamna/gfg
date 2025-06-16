// User function Template for C++
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long>ans;
        long long prod=1;
        for(int i=1;i<=n;i++){
            prod*=i;
            if(prod<=n){
                ans.push_back(prod);
            }
            else
            break;
        }
        return ans;
    }
};