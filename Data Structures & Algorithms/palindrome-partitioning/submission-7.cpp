class Solution {
    bool pallindrome(string s,int a,int b){
        while(a<b){
            if(s[a]!=s[b]){
                return 0;
            }
            a++;b--;
        }
        return 1;
    }
    void solve(string s,vector<vector<string>>&res,vector<string>&output,int index){
        if(index>=s.size()){
            res.push_back(output);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(pallindrome(s,index,i)){
                output.push_back(s.substr(index,i-index+1));
                solve(s,res,output,i+1);
                output.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>output;
        int index=0;
        solve( s,res,output,index);
        return res;
    }
};
