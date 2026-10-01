#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vs vector<string>
#define print(x) cout << (x)
#define printv(v) do { for(auto &elem:v) cout<<elem<<" "; } while(0)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define msi multiset<int>
#define msl multiset<long long>
#define si set<int>
#define sl set<long long>
#define mpii map<int,int>
#define mpll map<ll,ll>
#define mpsi map<string,int>
#define mpis map<int,string>
#define umpii unordered_map<int,int>
#define umpll unordered_map<ll,ll>
#define umpsi unordered_map<string,int>
const ll MOD = 998244353;

/*

*/

void solve(){
    ll n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //dp[i][0] = ways till i, where ith is honest
    //dp[i][1] = ways till i, where ith is liar
    vvl dp(n, vl(2, 0));
    //first person can always be liar
    dp[0][1] = 1;
    //first person honest -> must say 0
    if(a[0] == 0){
        dp[0][0] = 1;
    }
    for(int i=1;i<n;i++){
        //ith person is liar
        //previous must be honest
        dp[i][1] = dp[i-1][0];
        //ith and previous both honest
        if(a[i] == a[i-1]){
            dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
        }
        //previous is liar
        if(i == 1){
            if(a[i] == 1){
                dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
            }
        }
        else{
            if(a[i] == a[i-2] + 1){
                dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
            }
        }
    }
    ll ans = (dp[n-1][0] + dp[n-1][1]) % MOD;
    print(ans);
}

int main(){
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}