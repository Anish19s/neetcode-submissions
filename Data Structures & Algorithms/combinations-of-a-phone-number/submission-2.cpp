class Solution {
    void solve(vector<string>&ans,string &digits,int index,string output, string m[]){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int val=digits[index]-'0';
        string out=m[val];
        for(int i=0;i<out.length();i++){
            output.push_back(out[i]);
            solve(ans,digits,index+1,output,m);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
       string m[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        int index=0;
        string output="";
         if(digits.size()==0){
            return ans;
        }
        solve(ans,digits,index,output,m);
        return ans;
    }
};
