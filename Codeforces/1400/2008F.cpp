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

*/

//mod inverse from gfg

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to compute (x^y) % m using fast exponentiation
ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;

    ll p = power(x, y / 2, m);

    p = (1LL * p * p) % m;

    if (y & 1)
        p = (1LL * p * x) % m;

    return p;
}

// Function to find modular inverse of n under modulo m
// Assumption: m is prime
ll modInverse(ll n, ll m)
{
    if (gcd(n, m) != 1)
        return -1;

    return power(n, m - 2, m);
}

void solve(){
    ll n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll bwd=0;
    ll p=0;
    for(int i=n-1;i>=0;i--){
        ll cur = (a[i]*bwd)%MOD;
        p = (p+cur)%MOD;
        bwd = (bwd+a[i])%MOD;
    }
    ll comb = (n*(n-1))/2;
    comb%=MOD;
    ll q = modInverse(comb,MOD);
    ll ans = (p*q)%MOD;
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