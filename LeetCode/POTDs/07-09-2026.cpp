class Solution {
public:

    const long long MOD = 1e9+7;
    vector<long long> dp;

    long long soln(int i,string &s){
        if (i>=s.size()){
            return 1;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        vector<int> done(26,0);
        long long ans=1;
        for(int j=i;j<s.size();j++){
            if (!done[s[j]-'a']){
                done[s[j]-'a']=1;
                ans = (ans + soln(j+1,s))%MOD;
            }
        }
        return dp[i] = ans%MOD;
    }

    int distinctSubseqII(string s) {
        dp.resize(s.size(),-1);
        return (soln(0,s)-1+MOD)%MOD;
    }
};
