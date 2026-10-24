class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return 0;
        }
        sort(hand.begin(),hand.end());
        unordered_map<int,int>count;
        for(int num:hand){
            count[num]++;
        }   
        for(int num:hand){
            if(count[num]>0){
                for(int i=num;i<num+groupSize;i++){
                    if(count[i]==0){
                        return 0;
                    }
                    count[i]--;
                }
            }
        }
        return 1;
    }
};
//1 2 3 3 4 4 5