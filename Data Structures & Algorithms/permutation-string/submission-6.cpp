class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0,r=0,n=s2.size();
        vector<int>m1(26,0),m2(26,0);
        int i=0,n1=s1.size();
        while(i<n1){
            m1[s1[i]-'a']++;
            i++;
        }
        while(r<n){
            m2[s2[r]-'a']++;

            if(r-l+1>n1){
                m2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==n1 && m1==m2){
                return 1;
            }
            r++;
        }
        return 0;
    }
};
