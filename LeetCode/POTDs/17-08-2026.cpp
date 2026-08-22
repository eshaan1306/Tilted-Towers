class Solution {
public:

    vector<int> pref;
    vector<vector<int>> dp;

    int soln(vector<int> &stoneValue,int left,int right){
        if (left == right){
            return 0;
        }
        if (dp[left][right] != -1){
            return dp[left][right];
        }
        int first=0,second=0;
        int maxi=INT_MIN;
        for(int i=left;i<right;i++){
            first = pref[i+1] - pref[left];
            second = pref[right+1] - pref[i+1];
            if (first>second){
                int cur = second + soln(stoneValue,i+1,right);
                maxi = max(maxi,cur);
            }
            else if (second>first){
                int cur = first + soln(stoneValue,left,i);
                maxi = max(maxi,cur);
            }
            else{
                int op1 = second + soln(stoneValue,i+1,right);
                int op2 = first + soln(stoneValue,left,i);
                maxi = max(op1,op2);
            }
        }
        return dp[left][right] = maxi;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        pref.resize(n+1);
        dp.resize(n,
            vector<int>(n,-1)
        );
        pref[0] = 0;
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + stoneValue[i-1];
        }
        return soln(stoneValue,0,n-1);
    }
};
