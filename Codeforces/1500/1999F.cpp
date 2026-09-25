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
const ll MOD = 1e9 + 7;

/*
basically number of subsequences we can form 
such that count of 1>0
count of 1 must be k/2+1
*/

ll binpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vi a(n);
    ll cnt0=0,cnt1=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if (a[i] == 0){
            cnt0++;
        }
        else{
            cnt1++;
        }
    }
    if (cnt1 == 0){
        print(0);
        return;
    }
    vl dp1(cnt1+1,0);
    dp1[0] = 1;
    for(int i=1;i<=cnt1;i++){
        dp1[i] = dp1[i-1];
        dp1[i] = (dp1[i]*(cnt1-i+1))%MOD;
        dp1[i] = (dp1[i]*binpow(i,MOD-2))%MOD;
    }
    vl dp0(cnt0+1,0);
    dp0[0] = 1;
    for(int i=1;i<=cnt0;i++){
        dp0[i] = dp0[i-1];
        dp0[i] = (dp0[i]*(cnt0-i+1))%MOD;
        dp0[i] = (dp0[i]*binpow(i,MOD-2))%MOD;
    }
    ll ans=0;
    for(int ones=(k/2)+1;ones<=k;ones++){
        ll zeroes = k-ones;
        if(ones<=cnt1 && zeroes<=cnt0){
            ll prod = (dp1[ones]*dp0[zeroes])%MOD;
            ans = (ans + prod)%MOD;
        }
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