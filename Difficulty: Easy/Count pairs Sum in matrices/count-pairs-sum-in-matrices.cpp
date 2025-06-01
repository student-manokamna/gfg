class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        set<int>s1;
        set<int>s2;
        for(int i=0;i<mat1.size();i++){
            for(int j=0;j<mat1.size();j++){
            s1.insert(mat1[i][j]);
            s2.insert(mat2[i][j]);
        }
        }
        int count=0;
        
        for(auto y: s1){
            if(s2.find(x-y)!=s2.end())
            count++;
        }
        return count;
        
    }
};