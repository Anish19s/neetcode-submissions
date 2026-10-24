
class Solution {
public:
    string encode(vector<string>& strs) {
        string encode="";
        for(string str:strs){
            encode+=to_string(str.length())+'#'+str;
        }
        return encode;
    }

    vector<string> decode(string s) {
        int i=0;
         vector<string>res;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }       
            int len=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,len);
            res.push_back(word);
            i=j+len+1;
        }
        return res;
    }
};
