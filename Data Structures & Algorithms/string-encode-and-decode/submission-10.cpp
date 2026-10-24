
class Solution {
public:
    string encode(vector<string>& strs) {
        string enc="";
        for(string str:strs){
            enc+=to_string(str.length())+'#'+str;
        }
        return enc;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string>res;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int l=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,l);
            res.push_back(word);
            i=j+l+1;
        }
        return res;
    }
};
