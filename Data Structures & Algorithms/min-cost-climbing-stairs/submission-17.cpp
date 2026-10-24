class Solution {
    //recursion
    /*int solve(vector<int>& cost,int n){
        if(n==0||n==1){
            return cost[n];
        }
        return cost[n]+min(solve(cost,n-1),solve(cost,n-2));
    }*/
    //mem
    int solve(vector<int>& cost,int n,vector<int>&dp){
        if(n==0||n==1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));

        return cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       vector<int>dp(n,-1);
       //return min(solve(cost,n-2),solve(cost,n-1));
       return  min(solve(cost,n-2,dp),solve(cost,n-1,dp));
    }
};
