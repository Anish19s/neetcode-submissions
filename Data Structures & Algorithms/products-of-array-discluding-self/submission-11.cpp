class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),c1=0,prod=1;
        vector<int>out(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c1++;
                continue;
            }
            prod*=nums[i];
        } 
        if(c1>1){
            return out;
        }
        for(int i=0;i<n;i++){
            if(c1>0){
                out[i]=(nums[i]==0)?prod:0;
            }
            else{
                out[i]=prod/nums[i];
            }
        }
        return out;
    }
};
