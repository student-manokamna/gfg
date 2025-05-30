//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++


// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
          map<int,int>mp;
         mp[0]=1;
         int sum=0;
         int count=0;
        //   prefix sum
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mp.find(sum-k)!=mp.end()){
             count+=mp[sum-k];
            }
            //  if not match then add count by 1 
            mp[sum]++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends