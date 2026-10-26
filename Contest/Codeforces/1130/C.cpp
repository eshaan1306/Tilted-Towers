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
since the condition is one 
1 <= val <= k
definitely monotonic
so think of binary search
*/

bool check(vl &a,ll x,ll k){
    int n = a.size();
    vi pos(n,0);
    for(int i=1;i<n;i++){
        //we can colour both
        if (a[i] - a[i-1] <= k){
            pos[i] = 1;
            pos[i-1] = 1;
        }
    }
    vl left;
    for(int i=0;i<n;i++){
        if (!pos[i]){
            left.pb(a[i]);
        }
    }
    int m = left.size();
    ll req = 0;
    /*
    okay so the minimum answer for these is 
    m, where we can pair each of the left cells
    with some random cell, lets say cell-1
    so we would only need m extra
    but 2 cells can also share, if the distance between
    them is <= 2k
    so 1 can be reused
    */
    if (m == 0){
        return true;
    }
    req++;
    ll cur = left[0] + k;
    for(int i=1;i<m;i++){
        if (left[i] - cur <= k){
            //best
        }
        else{
            req++;
            cur = left[i] + k;
        }
    }
    return req <= x;
}

void solve(){
    int n,x;
    cin>>n>>x;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll low = 1, high = 1e9;
    ll ans = high;
    while(low <= high){
        ll mid = (low + high)/2;
        bool flag = check(a,x,mid);
        if (flag){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
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