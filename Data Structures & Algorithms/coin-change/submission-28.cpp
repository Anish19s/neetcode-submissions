class Solution {
    //recursion
   /* int solve(vector<int>& coins,int amt){
        if(amt==0){
            return 0;
        }
        if(amt<0){
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(coins,amt-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,ans+1);
            }
        }
        return mini;
    }*/
    //mem
    /*int solve(vector<int>& coins,int amt,vector<int>dp){
      if(amt==0){
            return 0;
        }
        if(amt<0){
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(coins,amt-coins[i],dp);
            if(ans!=INT_MAX){
                mini=min(mini,ans+1);
            }
        }
        return mini;
    }*/
    //mem
    int solve(vector<int>& coins,int amt){
        vector<int>dp(amt+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amt;i++){
            int mini=INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                    int ans=dp[i-coins[j]];
                    if(ans!=INT_MAX){
                        mini=min(mini,ans+1);
                    }
                }
            }
            dp[i]=mini;
        }
        return dp[amt];
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        return solve(coins,amount)==INT_MAX?-1:solve(coins,amount);
    }
};
