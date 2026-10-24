class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.size();
        unordered_map<int,int>freq;
        int maxl=0;
        while(r<n){
            freq[s[r]]++;

            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }

            maxl=max(maxl,r-l+1);
            r++;
        }   
        return maxl;
    }
};
