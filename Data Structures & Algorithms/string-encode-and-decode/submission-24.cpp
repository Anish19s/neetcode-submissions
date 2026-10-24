class Solution {
public:

    string encode(vector<string>& strs) {
        string enc="";

        for(int i=0;i<strs.size();i++){
            enc+=to_string(strs[i].size());
            enc+='#';
            enc+=strs[i];
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> fin;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int l=stoi(s.substr(i,j-i));
            string k=s.substr(j+1,l);
            fin.push_back(k);
            i=j+l+1;
        }
        return fin;
    }
};
