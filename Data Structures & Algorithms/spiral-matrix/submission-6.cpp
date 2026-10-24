class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startr=0, startc=0;
        int endr=matrix.size()-1,endc=matrix[0].size()-1;
        vector<int>res;
        int n=matrix.size(),m=matrix[0].size();
       while (startr <= endr && startc <= endc)
{
        for(int i=startc;i<=endc;i++){
            res.push_back(matrix[startr][i]);
        }
        startr++;
        for(int i=startr;i<=endr;i++){
            res.push_back(matrix[i][endc]);
        }
        endc--;
        if(startr<=endr){
        for(int i=endc;i>=startc;i--){
            res.push_back(matrix[endr][i]);
        }
        endr--;}
        if(startc<=endc){
        for(int i=endr;i>=startr;i--){
            res.push_back(matrix[i][startc]);
        }
        startc++;}
        }
        return res;
    }
};
