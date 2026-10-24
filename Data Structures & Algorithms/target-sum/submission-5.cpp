class Solution {
    int solve(vector<int>& nums,int ind, int target,int total){
        if(ind==nums.size()){
            return target==total;
        }
        return solve(nums,ind+1,target,total-nums[ind])+solve(nums,ind+1,target,total+nums[ind]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,target,0);
    }
};
