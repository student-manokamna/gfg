// User function Template for C++
class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        stack<string> st;

        for (const string& word : arr) {
            if (!st.empty() && st.top() == word) {
                st.pop();  // remove the previous same word
            } else {
                st.push(word);
            }
        }

        return st.size();  // words left after destruction
    }
};
