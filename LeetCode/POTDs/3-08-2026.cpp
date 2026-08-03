class Solution {
public:

    vector<vector<int>> dp;

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(
            n+1,vector<int>(
                2,0
            )
        );
        int tol=0;
        for(auto &s:stoneValue){
            tol+=s;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if (j){
                    int pick=0;
                    int maxi=INT_MIN;
                    for(int k=i;k<min(i+3,n);k++){
                        pick+=stoneValue[k];
                        int cur = pick + dp[k+1][!j];
                        maxi = max(maxi,cur);
                    }
                    dp[i][j]=maxi;
                }
                else{
                    int mini=INT_MAX;
                    for(int k=i;k<min(i+3,n);k++){
                        int cur = dp[k+1][!j];
                        mini = min(mini,cur);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        int alice = dp[0][1];
        int bob = tol - alice;
        if (alice>bob){
            return "Alice";
        }
        else if (alice<bob){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};
