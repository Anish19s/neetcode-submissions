class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int>temp;
        sort(nums.begin(),nums.end());
        temp.push_back(nums[0]);
        int c1=1,maxlen=INT_MIN;
        for(int i=0,j=i+1;j<nums.size();i++,j++){
            if((nums[j]-nums[i])==1){
                temp.push_back(nums[j]);
                c1++;
            }
            else if((nums[j]-nums[i])==0){
               continue;
            }
            else{
                temp.clear();
                if(c1>maxlen){
                    maxlen=c1;
                }
                c1=1;
            }
        }
        maxlen=max(maxlen,c1);
        return maxlen;
    }
};
