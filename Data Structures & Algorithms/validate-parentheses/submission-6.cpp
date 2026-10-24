#include<stack>
class Solution {
    bool match(char a,char b){
        if(a=='(' && b==')'){
            return 1;
        }
        if(a=='[' && b==']'){
            return 1;
        }
        if(a=='{' && b=='}'){
            return 1;
        }
        return 0;
    }
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return 0;
                }
                if(!match(st.top(),s[i])){
                    return 0;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            return 0;
        }
        return 1;
    }
};
