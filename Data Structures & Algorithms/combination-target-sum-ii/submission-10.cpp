class Solution {
    void solve(vector<int>& nums,vector<vector<int>>&res,vector<int>&output,int target,int index){
        if(target==0){
            res.push_back(output);
            return;
        }
        if(target<0||index>=nums.size()){
            return;
        }
        output.push_back(nums[index]);
        solve(nums,res,output,target-nums[index],index+1);
        output.pop_back();
        while(index+1<nums.size() && nums[index+1]==nums[index]){
            index++;
        }
        solve(nums,res,output,target,index+1);
      
        
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
