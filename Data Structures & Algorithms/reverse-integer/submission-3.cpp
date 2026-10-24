class Solution {
    long rec(int n,long re){
        if(n==0){
            return re;
        }
        re=re*10+n%10;
        return rec(n/10,re);
    }
public:
    int reverse(int x) {
        long r=rec(abs(x),0)*(x<0?-1:1);
        if(r<INT_MIN||r>INT_MAX){
            return 0;
        }
        return r;
    }
};
