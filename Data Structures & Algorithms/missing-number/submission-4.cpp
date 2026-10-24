class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xo=n;
        for(int i=0;i<n;i++){
            xo^=i^nums[i];
        }
        return xo;
    }
};
