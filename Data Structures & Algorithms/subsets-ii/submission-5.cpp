class Solution {
    void solve( vector<int>&nums, vector<int>&output, vector<vector<int>>&res,int index){
        if(index>=nums.size()){
            res.push_back(output);
            return;
        }
        output.push_back(nums[index]);
        solve(nums,output,res,index+1);
        output.pop_back();
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            index++;
        }

        solve(nums,output,res,index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>output;
        int index=0;
        sort(nums.begin(),nums.end());
        solve(nums,output,res,index);
        return res;
    }
};
