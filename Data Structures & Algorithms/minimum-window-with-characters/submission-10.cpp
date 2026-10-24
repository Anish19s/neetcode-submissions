class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,n=s.size(),x=t.size();
        int i=0;
        if(x>n){
            return "";
        }
        unordered_map<char,int>m;
        while(i<x){
            m[t[i]]++;
            i++;
        }
        int cnt=0,minI=-1,minL=INT_MAX;
        while(r<n){
            if(m[s[r]]>0){
                cnt++;
            }
            m[s[r]]--;
            while(cnt==x){
                if(r-l+1<minL){
                    minL=r-l+1;
                    minI=l;
                }
                m[s[l]]++;
                if(m[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return minI==-1?"":s.substr(minI,minL);
    }
};
