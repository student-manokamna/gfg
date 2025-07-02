class Solution {
  public:
    vector<int> topo(int n, vector<vector<int>>& adj) {
        vector<int> indeg(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i])
                indeg[it]++;
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }

        // if topological sort doesn't include all characters, return empty
        if (ans.size() < n) return {};

        return ans;
    }

    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<bool> present(26, false); // to track which letters actually appear

        // Mark characters that appear in words
        for (auto word : words) {
            for (auto ch : word) {
                present[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool foundDiff = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    foundDiff = true;
                    break;
                }
            }

            // ❗ Check invalid prefix order like: "abc" before "ab"
            if (!foundDiff && s1.size() > s2.size()) {
                return "";
            }
        }

        vector<int> res = topo(26, adj);
        string result = "";

        for (int i = 0; i < res.size(); i++) {
            if (present[res[i]])
                result += (char)(res[i] + 'a');
        }

        return result;
    }
};
