class Solution {
   void solve(vector<vector<int>>&final,vector<int>& nums,vector<int>&output,int index,int sum,int targ){
        if(index>=nums.size()||sum>targ){
            return;
        }
        if(sum==targ){
            final.push_back(output);
            return;
        }
        output.push_back(nums[index]);
        solve(final,nums,output,index,sum+nums[index],targ);
        output.pop_back();

        solve(final,nums,output,index+1,sum,targ);

   }
   
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<vector<int>>final;
       vector<int>out;
       int ind=0,sum=0;
       solve(final,nums,out,ind,sum,target);
       return final;
    }
};
