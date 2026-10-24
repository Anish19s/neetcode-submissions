class Solution {
    void solve(vector<int>& nums,vector<vector<int>>&res,int index, vector<int>output){
       if(index>=nums.size()){
            res.push_back(output);
            return;
       }
       solve(nums,res,index+1,output);

       output.push_back(nums[index]);
       solve(nums,res,index+1,output);
       output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>final;
        vector<int>output;
        int index=0;
        solve(nums,final,index,output);   
        return final;
    }
};
