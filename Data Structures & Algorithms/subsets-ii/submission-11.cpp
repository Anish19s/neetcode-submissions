class Solution {
    void solve(vector<int>& nums,vector<vector<int>>&fin,vector<int>&out,int ind){
        if(ind>=nums.size()){
            fin.push_back(out);
            return;
        }
        out.push_back(nums[ind]);
        solve(nums,fin,out,ind+1);
        out.pop_back();
        while(ind+1<nums.size() && nums[ind]==nums[ind+1]){
            ind++;
        }


        solve(nums,fin,out,ind+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>fin;
        vector<int>out;
        int ind=0;
        solve(nums,fin,out,ind);
        return fin;
    }
};
