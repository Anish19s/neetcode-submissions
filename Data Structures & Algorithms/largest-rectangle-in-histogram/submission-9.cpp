class Solution {
    vector<int>NextSmaller(vector<int>& heights){
        stack<int>st;
        int n=heights.size();
        vector<int>grt(n);

        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            grt[i]=(st.top()==-1?n:st.top());
            st.push(i);
        }

        return grt;
    }
    vector<int>prevSmaller(vector<int>& heights){
        stack<int>st;
        int n=heights.size();
        vector<int>grt(n);

        st.push(-1);
        for(int i=0;i<n;i++){
           while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            grt[i]=st.top();
            st.push(i);
        }
        return grt;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        vector<int>prev(n);

        next=NextSmaller(heights);
        prev=prevSmaller(heights);

        int maxA=INT_MIN ;
        for(int i=0;i<n;i++){
            int l=heights[i];

            int b=next[i]-prev[i]-1;
            maxA=max(maxA,l*b);
        }
        return maxA;
    }
};
