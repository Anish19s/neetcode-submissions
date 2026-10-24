class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
       int a=0,b=n-1;
        while(a<b){
            if(!isalnum(s[a])){
                a++;
                continue;
            }
            if(!isalnum(s[b])){
                b--;
                continue;
            }
            if(tolower(s[a])!=tolower(s[b])){
                return 0;
            }
            a++;b--;
        }
        return 1;
    }
};
