class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
            if(m[nums[i]]){
                return 1;
            }
            m[nums[i]]++;
       }
       return 0;
    }
};