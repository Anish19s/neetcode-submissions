class Solution {
    void solve(vector<vector<int>>&res,vector<int>& nums,int index){
        if(index>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(res,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int index=0;
        solve(res,nums,index);
        return res;
    }
};
