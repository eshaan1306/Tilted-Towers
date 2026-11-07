class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        //all the strings of length 1 and 2
        long long ans = n + n - 1;
        int l = 0,r = 2;
        while(r < n){
            if (s[r-2] == 'a' && s[r-1] == 'b' && s[r] == 'c'){
                long long len = r - l;
                ans += (len*(len+1))/2;
                ans -= len + len - 1;
                l = r - 1;
                r = r + 1;
            }
            else{
                r++;
            }
        }
        long long len = r - l;
        ans += (len*(len+1))/2;
        ans -= len + len - 1;
        return ans;
    }
};
