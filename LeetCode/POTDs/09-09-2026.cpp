class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cur = 1e3;
        int iter = 1;
        while(cur <= n){
            long long next = cur*1e3;
            next--;
            ans += iter*(min(n,next)-cur+1);
            cur = cur*1e3;
            iter++;
        }
        return ans;
    }
};
