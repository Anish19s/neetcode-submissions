class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return 0;
        }
       unordered_map<char,int>m;
        unordered_map<char,int>n;
       for(int i=0;i<s.size();i++){
            m[s[i]]++;
       }
       for(int i=0;i<t.size();i++){
            n[t[i]]++;
       }
       for(int i=0;i<s.size();i++){
            if(m[s[i]]!=n[s[i]]||m[t[i]==n[t[i]]]){
                return 0;
            }
       }
       return 1;
    }
};
