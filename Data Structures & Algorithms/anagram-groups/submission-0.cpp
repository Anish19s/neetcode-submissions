class Solution {
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (char c : t) {
            if (--freq[c] < 0) return false;
        }
        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> visited(strs.size(), false); // mark visited strings

        for (int i = 0; i < strs.size(); i++) {
            if (visited[i]) continue;

            vector<string> temp;
            temp.push_back(strs[i]);
            visited[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (!visited[j] && isAnagram(strs[i], strs[j])) {
                    temp.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

