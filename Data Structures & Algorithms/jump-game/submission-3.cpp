class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxI=nums[0];
        for(int i=0;i<nums.size();i++){
            if(i>maxI){
                return 0;
            }
            maxI=max(i+nums[i],maxI);
        }
        return 1;
    }
};
