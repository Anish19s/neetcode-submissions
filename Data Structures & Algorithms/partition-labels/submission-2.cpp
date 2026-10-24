class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        int end=0,len=0;
        vector<int>v;
       for(int i=0;i<s.length();i++){
            len++;
            end=max(end,m[s[i]]);

            if(i==end){
                v.push_back(len);
                len=0;
            }
       }
       return v;
    }
};
