class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v1;
        int n=position.size();
        for(int i=0;i<n;i++){
            v1.push_back({position[i],speed[i]});
        }

        stack<double>st;

        sort(v1.begin(),v1.end(),greater<>());

        for(auto& vi:v1){
            
            double t=(double)(target-vi.first)/vi.second;

            if(st.empty()||(!st.empty() && t>st.top())){
                st.push(t);
            }
        }
        return st.size();
    }
};
