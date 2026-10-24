class Solution {
    void solve(vector<int>& nums, vector<vector<int>>&res,vector<int>&output,int target,int index){
        if(target==0){
            res.push_back(output);
            return;
        }
            if(index>=nums.size()||target<0){
            return;
        }
        output.push_back(nums[index]);
        solve(nums,res,output,target-nums[index],index);
        output.pop_back();

        solve(nums,res,output,target,index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>output;
        int index=0;
        solve(nums,res,output,target,index);
        return res;
    }
};
