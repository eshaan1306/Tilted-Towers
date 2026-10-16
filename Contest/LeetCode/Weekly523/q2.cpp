class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        vector<int> sieve(n+1,1);
        for(int i=2;i<=n;i++){
            sieve[i] = i;
        }
        for(int i=2;i<=n;i++){
            if (sieve[i] == i){
                if (s >= i){
                    s -= i;
                    ans.push_back(i);
                }
                for(long long j=1LL*i*i;j<=n;j+=i){
                    sieve[j] = i;
                }
            }
        }
        return ans;
    }
};
