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
1 2 3 4
1 2 3 4 5 6
*/

void solve(){
    int n;
    cin>>n;
    vl a(n);
    for (auto &x:a){
        cin>>x;
    }
    int m = n - 4;
    vl b(m);
    mpll freq;
    for (int i = 0; i < m; i++) {
        b[i] = a[i] + a[i+2] - a[i+4];
        freq[b[i]]++;
    }
    ll ans = 0;
    for(auto &it:freq){
        ans += (it.second * (it.second - 1)) / 2;
    }
    for (int i=0;i<m;i++){
        if (i + 2 < m && b[i] == b[i+2])
            ans--;
        if (i + 4 < m && b[i] == b[i+4])
            ans--;
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