
class Solution {
public:

    const int INF = 1e9;

    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> sieve(n+1,1);
        for(int i=2;i<=n;i++){
            sieve[i] = i;
        }
        vector<int> primes;
        for(int i=2;i<=n;i++){
            if(sieve[i] == i){
                primes.push_back(i);
                for(long long j=1LL*i*i;j<=n;j+=i){
                    sieve[j] = i;
                }
            }
        }
        int m = primes.size();
        // figure out maximum possible sum
        vector<vector<int>> pos(m+1,
            vector<int>(s+1,0));
        pos[0][0] = 1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=s;j++){
                // check if possible without current
                pos[i][j] = pos[i-1][j];
                if(primes[i-1] <= j){
                    pos[i][j] |= pos[i-1][j-primes[i-1]];
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=s;i++){
            if(pos[m][i]){
                maxi = i;
            }
        }
        // dp[i][j] = min primes to form sum j
        // using primes from index i onwards
        vector<vector<int>> dp(m+1,
            vector<int>(maxi+1,INF));
        dp[m][0] = 0;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<=maxi;j++){
                dp[i][j] = dp[i+1][j];
                if(primes[i] <= j &&
                   dp[i+1][j-primes[i]] != INF){
                    dp[i][j] = min(dp[i][j],
                        1+dp[i+1][j-primes[i]]);
                }
            }
        }
        // reconstruction
        vector<int> ans;
        int rem = maxi;
        int cnt = dp[0][maxi];
        for(int i=0;i<m && cnt>0;i++){
            if(primes[i] <= rem && dp[i+1][rem-primes[i]] == cnt-1){
                ans.push_back(primes[i]);
                rem -= primes[i];
                cnt--;
            }
        }
        return ans;
    }
};
