class Solution {
public:

    /*
    only question is does going to the max thing
    always gives me the answer
    we can actualy make pairs 
    so 
    [1....i] + 1[....j] == n
    thi sis root n 
    maybe dp 
    to make n, i have basically root n only options 
    so n root n should work 
    */

    vector<int> dp;

    long long helper(int n){
        return (1LL*n*(n+1))/2;
    }

    int soln(int n){
        if (n==0){
            return 0;
        }
        if (dp[n] != -1){
            return dp[n];
        }
        //dys we go continuous till
        int mini = INT_MAX;
        for(int d=1;helper(d)<=n;d++){
            int cur = d + 1 + soln(n-helper(d));
            mini=min(mini,cur);
        }
        return dp[n]=mini;
    }
    
    int minDays(int n) {
        dp.resize(n+1,-1);
        return soln(n)-1;
    }
};
