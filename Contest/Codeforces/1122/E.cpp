#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define vi vector<int>
#define vl vector<ll>
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
    int n,k;
    cin>>n>>k;
    vl a(n);
    ll maxi = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi = max(maxi,a[i]);
    }
    vi sieves(maxi+1,0);
    for(int i=1;i<=maxi;i++){
        sieves[i] = i;
    }
    for(int i=2;i<=maxi;i++){
        if (sieves[i] != i){
            continue;
        }
        for(ll j=1LL*i*i;j<=maxi;j+=i){
            sieves[j] = i;
        }
    }
    vl dp(maxi+1,0);
    for(ll i=k+1;i<=maxi;i++){
        sl st;
        ll temp = i;
        while(temp > 1){
            st.insert(sieves[temp]);
            temp/=sieves[temp];
        }
        ll minCnt = INT_MAX;
        for(auto &p:st){
            ll curCnt = 1 + p*dp[i/p];
            minCnt = min(minCnt,curCnt);
        }
        dp[i] = minCnt;
    }
    ll ans = 0;
    for(auto &x:a){
        ans += dp[x];
    }
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