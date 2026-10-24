class Solution {
public:
    double myPow(double x, int n) {
        if(x==0||x==1){
            return x;
        }
        double res=1;
        long pow=abs((long)n);

        while(pow){
            if(pow & 1){
                res*=x;
            }
            x*=x;
            pow=(pow)>>1;
        }
        return (n>=0)?res:1/res;
    }
};
