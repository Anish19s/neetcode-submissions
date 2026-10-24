class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currS=nums[0],maxs=nums[0];
       for(int i=1;i<nums.size();i++){
            currS=max(currS+nums[i],nums[i]);
            maxs=max(currS,maxs);
       }
       return maxs;
    }
};
