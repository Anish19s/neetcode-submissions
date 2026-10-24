class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0,end=matrix.size()*matrix[0].size()-1;
        int row=matrix.size(),col=matrix[0].size();
        while(start<=end){
            int mid=(start+end)/2;
            int el=matrix[mid/col][mid%col];
            if(el==target){
                return 1;
            }
            else if(el>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return 0;
    }
};
