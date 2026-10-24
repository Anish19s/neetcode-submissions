class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size(),maxl=0,maxf=0;
        vector<int>freq(26);
        while(r<n){
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);

            while((r-l+1)-maxf>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxl=max(maxl,r-l+1);
            r++;
        }
        return maxl;
    }
};
