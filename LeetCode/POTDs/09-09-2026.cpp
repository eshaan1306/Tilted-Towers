class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cur = 1e3;
        // int iter = 1;
        while(cur <= n){
            ans += n-cur+1;
            cur = cur*1e3;
        }
        return ans;
    }
};
