class Solution {
public:

    string encode(vector<string>& strs) {
        string enc="";
        for(string s:strs){
            enc+=to_string(s.size())+'#'+s;
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

            int x=stoi(s.substr(i,j-i));
            string k=s.substr(j+1,x);
           
           fin.push_back(k);
           i=j+x+1;

        }
        return fin;
    }
};
