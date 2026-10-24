
class Solution {
public:
    string encode(vector<string>& strs) {
       string enc="";
       for(auto& str:strs){
        enc+=to_string(str.length())+"#"+str;
       }
       return enc;
    }

    vector<string> decode(string s) {
        vector<string>fin;
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int l=stoi(s.substr(i,j-i+1));
            string k=s.substr(j+1,l);
            i=j+l+1;
            fin.push_back(k);
        }
        return fin;
    }
};
