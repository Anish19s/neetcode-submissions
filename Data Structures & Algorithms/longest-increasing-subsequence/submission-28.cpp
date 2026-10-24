class Solution {
    //recursion
    /*int solve(vector<int>& nums,int ind,int prev){
        if(ind>=nums.size()){
            return 0;
        }
        int ans=INT_MIN;
        for(int i=ind;i<nums.size();i++){
            int incl=0;
            if(prev==INT_MIN||nums[i]>prev){
                 incl=1+solve(nums,i+1,nums[i]);
            }
            int excl=solve(nums,i+1,prev);

            ans=max(ans,max(incl,excl));
        }
        return ans;
    }*/
    //MEM
    int solve(vector<int>& nums,int ind,int prev, vector<vector<int>>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(prev!=INT_MIN && dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        int excl=solve(nums,ind+1,prev,dp);

        int ans=INT_MIN;
       
        int incl=0;
        if(prev==-1||nums[ind]>nums[prev]){
            incl=1+solve(nums,ind+1,ind,dp);
        }
        ans=max(ans,max(incl,excl));
       
        dp[ind][prev+1]=ans;
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};
