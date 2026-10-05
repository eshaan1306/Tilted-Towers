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

void solve(){
    ll n,x;
    cin>>n>>x;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=0;
    ll cur = 0;
    //number of subarrays with sum less than or equal to x starting at index i
    /*
    so see lets say we have arr[l..r] with sum s <= x
    lets say arr[l..r+1] sum s > x, so we stire g as 0 
    but but since the we reset from 0, we can consider all the subarrays starting from
    r+2, with total g as 0
    */
    vl dp(n+1,0);
    while(r<n){
        cur += a[r];
        while(cur > x && l<=r){
            cur -= a[l];
            l++;
        }
        if (cur <= x){
            dp[l]++;
            dp[r+1]--;
        }
        r++;
    }
    for(int i=1;i<n;i++){
        dp[i] += dp[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ll cnt = dp[i];
        ll nextIndx = i + cnt;
        if (nextIndx + 1 < n){
            dp[i] += dp[nextIndx + 1];
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans += dp[i];
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