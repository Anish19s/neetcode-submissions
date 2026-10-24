class Solution {
    void solve(vector<int>& nums,vector<vector<int>>&res,vector<int>&output,int target,int index){
        if(target==0){
            res.push_back(output);
            return;
        }
        if(target<0||index>=nums.size()){
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(nums[i]==nums[i-1] && i>index){
                continue;
            }
            if(nums[i]>target){
                break;

            }
            output.push_back(nums[i]);
             solve(nums,res,output,target-nums[i],i+1);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int>output;
        int index=0;
        solve(candidates,res,output,target,index);
        return res;
    }
};
