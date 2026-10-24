class Solution {
public:
    int solve2(vector<int>&nums,int n){
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<n;i++){
            int incl=prev2+nums[i];
            int excl=prev1;
            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int solve(vector<int>& nums){
        return solve2(nums,nums.size());
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>first,second;
        for(int i=0;i<nums.size();i++){
            if(i!=nums.size()-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(second));
    }
};
