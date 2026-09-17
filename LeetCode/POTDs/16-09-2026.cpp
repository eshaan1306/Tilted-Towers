class Solution {
public:

    const long long MOD = 1e9+7;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n,
            vector<long long>(k+1,0));
        vector<vector<long long>> pref(n+1,
            vector<long long>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
            pref[i+1][0] = i+1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                //skip here
                long long cnt = dp[i-1][j];
                //draw here
                cnt = (cnt + pref[i][j-1])%MOD;
                dp[i][j] = cnt;
                pref[i+1][j] = (pref[i][j] + dp[i][j])%MOD;
            }
        }
        return dp[n-1][k];
    }
};
