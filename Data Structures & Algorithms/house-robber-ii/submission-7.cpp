class Solution {
    int solve(vector<int>& nums,int ind,int n,vector<int>&dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int incl=nums[ind]+solve(nums,ind+2,n,dp);
        int excl=solve(nums,ind+1,n,dp);

        dp[ind]=max(incl,excl);
        

        return max(incl,excl);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n,-1);
       int f=solve(nums,0,n-1,dp1);
       int s=solve(nums,1,n,dp2);
        return max(f,s);
    }
};
