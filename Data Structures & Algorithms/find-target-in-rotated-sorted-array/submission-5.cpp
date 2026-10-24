class Solution {
    int bs(vector<int>& nums, int target,int s,int e) {
        int start=s,end=e;
        int mid=0;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid=0;
        while(start<end){
             mid=(start+end)/2;
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        int pivot=start;
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            return bs(nums,target,pivot,nums.size()-1);
        }
        return bs(nums,target,0,pivot-1);
    }
};
