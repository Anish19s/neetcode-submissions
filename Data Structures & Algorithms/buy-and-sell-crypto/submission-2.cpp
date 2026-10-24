class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mins=prices[0],maxp=INT_MIN;
        for(auto sell:prices){
            maxp=max(maxp,sell-mins);
            mins=min(mins,sell);
        }
        return maxp;
    }
};
