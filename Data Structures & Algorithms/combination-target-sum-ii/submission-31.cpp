class Solution {
   void solve(vector<int>& candidates,vector<vector<int>>&final,vector<int>&out,int ind,int targ){
        if(targ==0){  
            final.push_back(out);
            return;
        }
        
        if(ind>=candidates.size()||targ<0){
            return;
        }
        out.push_back(candidates[ind]);
        solve(candidates,final,out,ind+1,targ-candidates[ind]);
        out.pop_back();
         while(ind+1<candidates.size() && candidates[ind]==candidates[ind+1]){
            ind++;
        }


        solve(candidates,final,out,ind+1,targ);

   }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>final;
        vector<int>out;
        int ind=0;
        solve(candidates,final,out,ind,target);
        return final;
    }
};
//1 2 2 4 5 6 9