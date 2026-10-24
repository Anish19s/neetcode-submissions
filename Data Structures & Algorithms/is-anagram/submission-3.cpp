class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        unordered_map<char,int>seen1;
        unordered_map<char,int>seen2;
        for(int i=0;i<s.length();i++){
            seen1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            seen2[t[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(seen1[s[i]]!=seen2[s[i]]){
                return 0;
            }
        }
        return 1;
    }
};
