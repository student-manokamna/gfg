class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int l =0;
        int r=arr.size()-1;
  int ans=-1;
        while(l<=r){
                  int mid = l+(r-l)/2;
                  if(arr[mid]>x){
                      r=mid-1;
                  }
                  else if(arr[mid]<=x){
                      ans=mid;
                      l=mid+1;
                  }
        }
        return ans;
        
    }
};
