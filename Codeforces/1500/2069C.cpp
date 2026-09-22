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
basically needs to be bounded by 1 and 3
for every pair 1 and 3 (in order)
cout the number of 2s between them 
*/

void solve(){
    ll n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll cur = 0;
    ll cnt = 0;
    vl dp(n);
    for(int i=0;i<n;i++){
        if (a[i] == 1){
            cnt++;
        }
        else if (a[i] == 2){
            //the ones starting from it 
            ll tol = cnt;
            //plus we can add this 2 to the cur cnt
            tol = (tol+cur)%MOD;
            cur = (cur+tol)%MOD;;
            dp[i] = tol;
        }
    }
    cnt=0;
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        if (a[i] == 3){
            cnt++;
        }
        else if (a[i] == 2){
            ll ways = (dp[i]*cnt)%MOD;
            ans = (ans+ways)%MOD;
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