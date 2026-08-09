class Solution {
public:

    vector<vector<vector<int>>> dp;

    int soln(int i,vector<int> &piles,int m,bool flag){
        if (i>=piles.size()){
            return 0;
        }
        if (dp[i][m][flag] != -1){
            return dp[i][m][flag];
        }
        if (flag){
            int taken=0;
            int maxi=INT_MIN;
            for(int j=i;j<min((int)piles.size(),i+2*m);j++){
                int x = j-i+1;
                taken += piles[j];
                int cur = taken + soln(j+1,piles,max(m,x),!flag);
                maxi = max(maxi,cur);
            }
            return dp[i][m][flag] = maxi;
        }
        else{
            int mini=INT_MAX;
            for(int j=i;j<min((int)piles.size(),i+2*m);j++){
                int x = j-i+1;
                int cur = soln(j+1,piles,max(m,x),!flag);
                mini = min(mini,cur);
            }
            return dp[i][m][flag] = mini;
        }
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n,
            vector<vector<int>>(n+1,
                vector<int>(2,-1)
            )
        );
        return soln(0,piles,1,true);
    }
};
