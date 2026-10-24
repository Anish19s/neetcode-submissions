class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int maxb=0,maxl=0,maxA=0,res;
        while(l<r){
            maxA=min(heights[l],heights[r])*(r-l);
            res=max(res,maxA);
            if(heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }

        }
        return res;
    }
};
