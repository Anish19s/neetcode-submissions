class Solution {
    //recursion
    /*int solve(vector<int>& nums,int ind){
        if(ind>=nums.size()){
            return 0;
        }
        int incl=nums[ind]+solve(nums,ind+2);
        int excl=solve(nums,ind+1);

        return max(incl,excl);
    }*/
    //mem
    int solve(vector<int>& nums,int ind,vector<int>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int incl=nums[ind]+solve(nums,ind+2,dp);
        int excl=solve(nums,ind+1,dp);

        dp[ind]=max(incl,excl);

        return max(incl,excl);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       return solve(nums,0,dp);
    }
};
