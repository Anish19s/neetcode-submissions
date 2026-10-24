class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,cnt=0;

        while(r<n-1){
            int fart=0;
            while(l<=r){
                fart=max(fart,l+nums[l]);
                l++;
            }
            r=fart;
            cnt++;
        }  
        return cnt; 
    }
};
