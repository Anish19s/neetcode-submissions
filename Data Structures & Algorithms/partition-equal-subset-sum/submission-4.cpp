class Solution {
    //rec
    /*bool solve(vector<int>& nums,int sum,int ind){
        if(ind>=nums.size()){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        int incl=solve(nums,sum-nums[ind],ind+1);
        int excl=solve(nums,sum,ind+1);

        return incl||excl;
    }*/
    //tab
    bool solve(vector<int>& nums,int sum,int ind,vector<vector<int>>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int incl=solve(nums,sum-nums[ind],ind+1,dp);
        int excl=solve(nums,sum,ind+1,dp);

        dp[ind][sum]=incl||excl;
        return incl||excl;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum1=0;
        for(auto& n:nums){
            sum1+=n;
        }
        if(sum1%2!=0){
            return 0;
        }
        int x=nums.size();
        vector<vector<int>>dp(x,vector<int>(sum1/2+1,-1));
        return solve(nums,sum1/2,0,dp);
    }
};
