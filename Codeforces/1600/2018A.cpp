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
For deck size d:
q = number of decks
need :
q*d >= sum
q*d <= sum+k
q >= max(a[i])
hence
q >= max(maxA, ceil(sum/d))
q <= floor((sum+k)/d)
*/

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    vl a(n);
    ll sum = 0;
    ll mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    int ans = 1;
    for(ll d = 1; d <= n; d++){
        ll lower = max(mx, (sum + d - 1) / d);
        ll upper = (sum + k) / d;
        if(lower <= upper){
            ans = d;
        }
    }
    print(ans);
}

int main(){
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
    return 0;
}