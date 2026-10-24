class Solution {
    int co(int n){
        int cnt=0;
        for(int i=0;i<32;i++){
            if((1<<i)&n){
                cnt++;
            }
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int>out;
        for(int i=0;i<=n;i++){
            out.push_back(co(i));
        }
        return out;
    }
};
