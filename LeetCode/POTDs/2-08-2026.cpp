class Solution {
public:

    vector<vector<vector<int>>> dp;

    int soln(int i,int j,vector<int> &nums,int chance){
        if (i>j){
            return 0;
        }
        if (dp[i][j][chance] != INT_MIN){
            return dp[i][j][chance];
        }
        if (chance){
            int opt1 = nums[i] + soln(i+1,j,nums,!chance);
            int opt2 = nums[j] + soln(i,j-1,nums,!chance);
            return dp[i][j][chance] = max(opt1,opt2);
        }
        else{
            int opt1 = soln(i+1,j,nums,!chance);
            int opt2 = soln(i,j-1,nums,!chance);
            return dp[i][j][chance] = min(opt1,opt2);
        }
    }

    bool stoneGame(vector<int>& piles) {
        int tol=0;
        for(auto &p:piles){
            tol+=p;
        }
        int n = piles.size();
        dp.resize(n,
                vector<vector<int>>(n,
                    vector<int>(2,INT_MIN)
                )
        );
        int maxi = soln(0,n-1,piles,1);
        if (maxi > tol/2){
            return true;
        }
        return false;
    }
};
