class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(n,vector<int>(k+2,1e9));
        dp[src][0]=0;
        for(int i=1;i<=k+1;i++){
            for(auto &f:flights){
                int u=f[0];
                int v=f[1];
                int p=f[2];
                dp[v][i]=min(dp[v][i],dp[v][i-1]);
                if (dp[u][i-1]!=1e9){
                    dp[v][i]=min(dp[v][i],dp[u][i-1]+p);
                }
            }
        }
        if (dp[dst][k+1]==1e9){
            dp[dst][k+1]=-1;
        }
        return dp[dst][k+1];
    }
};
