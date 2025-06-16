// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        stack<int>st1;
         stack<int>st2;
         int c=0;
         vector<int>ans;
         for(int i=0;i<str.size();i++){
             if(str[i]=='('){
                 c=c+1;
                 st1.push(c);
                 
                 ans.push_back(c);
             }
             if(str[i]==')'){
               st2.push(st1.top());
               st1.pop();
                ans.push_back(st2.top());
             }
             
         }
         return ans;
        
    }
};