class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const string &a, const string &b) {
                 if (a.size() != b.size()) 
                     return a.size() < b.size();
                 return a < b;
             });
        
        unordered_set<string> good;
        string answer = "";
        
        for (auto &w : words) {
            if (w.size() == 1 || good.count(w.substr(0, w.size()-1))) {
                good.insert(w);
               
                if (w.size() > answer.size() ||
                   (w.size() == answer.size() && w < answer)) {
                    answer = w;
                }
            }
        }
        
        return answer;
    }
};
