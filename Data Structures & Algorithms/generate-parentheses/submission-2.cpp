class Solution {
    void solve(vector<string>&fin,int op,int cl,string s,int n){
        if(op==n && cl==n){
            fin.push_back(s);
            return;
        }
        if(op<n){
            solve(fin,op+1,cl,s+'(',n);
        }
        if(cl<op){
            solve(fin,op,cl+1,s+')',n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>fin;
        solve(fin,0,0,"",n);
        return fin;
    }
};
