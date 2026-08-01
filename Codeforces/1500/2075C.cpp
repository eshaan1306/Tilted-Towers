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
so basically the calculation is 
we will pick two elements a[i] and a[j]
firstly a[i]+a[j]>=n
then the number of ways are just 
using those 2 colours
(a[i]+a[j])-n+1 
and the above multiplied by two because like
ab and ba
i think we have a special case when one of them is n
then the number of ways are just the count of the other one
what if both n, then number of ways are just n-1
*/

void solve(){
    int n,m;
    cin>>n>>m;
    vl a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    ll ans=0;
    //x to store the <n and y==n
    vl x,y;
    for(auto &el:a){
        if (el==n){
            y.pb(el);
        }
        else{
            x.pb(el);
        }
    }
    //cases for n
    if (y.size()){
        ll sz=y.size();
        ans += (n-1)*((sz*(sz-1))/2);
        for(auto &el:x){
            ans += (el*sz);
        }
    }
    //cases for <n
    sort(all(x));
    int sz=x.size();
    vl suff(sz+1);
    suff[sz]=0;
    for(int i=sz-1;i>=0;i--){
        suff[i] = (x[i]+suff[i+1]);
    }
    for(int i=0;i<sz;i++){
        ll req=n-x[i];
        auto it = lower_bound(x.begin()+i+1,x.end(),req);
        int indx=it-x.begin();
        ll cnt=sz-indx;
        ll ways = (suff[indx] + (cnt*x[i])) - n*cnt + cnt;
        ans+=ways;
    }
    print(ans*2);
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