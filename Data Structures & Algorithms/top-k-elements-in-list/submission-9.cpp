#include <vector>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>seen1,seen2;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            seen1[nums[i]]++;
        }
         for(auto& pair:seen1){
            v.push_back({pair.second,pair.first});
        }
        sort(v.rbegin(),v.rend());
        vector<int> fin;
        for(int i=0;i<k;i++){
            fin.push_back(v[i].second);
        }
        return fin;
    }
};
