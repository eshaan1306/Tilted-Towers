class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=max(i-3,0);j<i;j++){
                int curCost = costs[i-1];
                curCost += (i-j)*(i-j);
                dp[i] = min(dp[i],dp[j] + curCost);
            }
        }
        return dp[n];
    }
};
