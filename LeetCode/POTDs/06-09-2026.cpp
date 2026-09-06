class Solution {
public:

    vector<vector<int>> dp;

    int soln(int i,int j,string &s,string &t){
        if (j==t.size()){
            return 1;
        }
        if (i==s.size()){
            return 0;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int cnt=soln(i+1,j,s,t);
        if (s[i]==t[j]){
            cnt+=soln(i+1,j+1,s,t);
        }
        return dp[i][j]=cnt;
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.resize(n,vector<int>(m,-1));
        return soln(0,0,s,t);
    }
};
