class Solution {
    int op(int a,int b,string c){
        if(c=="+"){
            return a+b;
        }
        else if(c=="*"){
            return a*b;
        }
        else if(c=="-"){
            return a-b;
        }
        return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();

        for(int i=0;i<n;i++){
            
            if(tokens[i]=="+"||tokens[i]=="*"||tokens[i]=="/"||tokens[i]=="-"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();

                int res=op(a,b,tokens[i]);
                st.push(res);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }   
        return st.top();
    }
};
