class Solution {
    int square(int n){
        int sum=0;
        while(n!=0){
            int a=n%10;
            sum+=(a*a);
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_map<int,int>m;
        int sum=0;
        unordered_map<int,int>seen;
        while(n!=1){
            n=square(n);
            if(seen[n]){
                return 0;
            }
            seen[n]++;
        }
        return 1;
    }
};
