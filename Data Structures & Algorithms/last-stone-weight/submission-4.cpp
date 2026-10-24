class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>m;
        for(int i=0;i<stones.size();i++){
            m.push(stones[i]);
        }
        while(m.size()!=1){
            int x=m.top();
            m.pop();
            int y=m.top();
            if(x==y){
                m.pop();
            }
            else if(x>y){
                m.pop();
                m.push(x-y);
            }
            if(m.empty()){
                return 0;
            }
        }
        if(m.empty()){
            return 0;
        }
        return m.top();
    }
};
