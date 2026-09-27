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
a b c are bounded by 
root n 
so we can iterate over values of 2, 
and calc the possible values of the third
*/

void solve(){
    ll n,x;
    cin>>n>>x;
    ll ans = 0;
    for(ll a=1; a+2<=x && 2*a+1<=n; a++){
        for(ll b=1; (a+b+1<=x && a*b+a+b<=n); b++){
            ll prod =  a*b;
            ll sum = a+b;
            if ((sum >= x) || (prod >= n)){
                break;
            }
            ll bound1 = x - sum;
            /*
            prod + sum(c) <= n
            sum*c <= n-prod
            c <= n-prod / sum
            */
            ll bound2 = (n-prod)/sum;
            ll minBound = min(bound1,bound2);
            ll tol = max(0LL,minBound);
            ans += tol;
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