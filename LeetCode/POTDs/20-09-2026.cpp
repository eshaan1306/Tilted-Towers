class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            int pos = 26 - (ch-'a');
            ans += (i+1)*pos;
        }
        return ans;
    }
};
