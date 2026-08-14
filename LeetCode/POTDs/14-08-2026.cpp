class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l=0,r=0,ans=0;
        unordered_map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                if (mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
