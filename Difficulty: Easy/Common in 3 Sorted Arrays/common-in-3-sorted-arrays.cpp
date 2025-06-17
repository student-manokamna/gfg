class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        set<int>s1;
         set<int>s2;
         set<int>s3;
           for(int i=0;i<arr3.size();i++){
                s3.insert(arr3[i]);
           }
           vector<int>v(s3.begin(),s3.end());
         
        vector<int>ans;
        
        
        for(int i=0;i<arr1.size();i++){
            s1.insert(arr1[i]);
        }
          
        for(int i=0;i<arr2.size();i++){
            s2.insert(arr2[i]);
        }
         for(int i=0;i<v.size();i++){
             if(s1.find(v[i])!=s1.end() && s2.find(v[i])!=s2.end())
             ans.push_back(v[i]);
         }
         return ans;
    }
};