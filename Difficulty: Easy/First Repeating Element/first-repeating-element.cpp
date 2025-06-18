class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        map<int,int>mp;
        for(auto c:arr)
        mp[c]++;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end() && mp[arr[i]]>1)
            {
                return i+1;
            }
        }
         return -1;
    }
};