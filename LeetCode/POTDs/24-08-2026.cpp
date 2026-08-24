class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> pref(n);
        pref[0] = stones[0];

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + stones[i];
        }

        int dp = pref[n-1];

        for(int i=n-2;i>=1;i--){
            dp = max(dp,pref[i] - dp);
        }

        return dp;
    }
};
