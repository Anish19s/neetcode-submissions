class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>output(n,0);
        int prod=1,c1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c1++;
                continue;
            }
            prod*=nums[i];
        }
        if(c1>1){
            return output;
        }
        for(int i=0;i<nums.size();i++){
            if(c1==1){
                output[i]=(nums[i]==0)?prod:0;}
            else{
                output[i]=prod/nums[i];
            }
        }
        return output;
    }
};
