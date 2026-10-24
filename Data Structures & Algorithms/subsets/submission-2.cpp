class Solution {
    void solve(vector<int>& nums,vector<vector<int>>&res,int index, vector<int>output){
        if(index>=nums.size()){
            res.push_back(output);
            return;
        }
        output.push_back(nums[index]);
        solve(nums,res,index+1,output);
        output.pop_back();

        solve(nums,res,index+1,output);
       
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>output;
        int index=0;
        solve(nums,res,index,output);
        return res;
    }
};
