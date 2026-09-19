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
    ll n,l,r;
    cin>>n>>l>>r;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    /*
    if we choose p <= a[i]
    then the cost is a[i]-p
    if we choose p >= a[i]
    then the cost is p-a[i]
    */
    sort(all(a));
    vl pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i-1];  
    }
    vl suff(n+1,0);
    for(int i=n-1;i>=0;i--){
        suff[i]=suff[i+1]+a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        /*
        case 1:
        ignore a[i]
        [0 ... i-1] -> p-a[j]
        i -> ignored
        [i+1 ... n-1] -> a[j]-p
        */
        {
            ll left=i;
            ll right=n-i-1;
            ll cost=0;
            ll b=left-right;
            if(i){
                cost-=pref[i];
            }
            if(i<n-1){
                cost+=suff[i+1];
            }
            ans=max(ans,min(cost+b*l,cost+b*r));
        }

        /*
        case 2:
        don't ignore anything
        [0 ... i] -> p-a[j]
        [i+1 ... n-1] -> a[j]-p
        */
        {
            ll left=i+1;
            ll right=n-i-1;
            ll cost=0;
            ll b=left-right;
            cost-=pref[i+1];
            if(i<n-1){
                cost+=suff[i+1];
            }
            ans=max(ans,min(cost+b*l,cost+b*r));
        }
    }
    /*
    special case:
    all of them are a[i]-p
    */
    {
        ll cost=pref[n];
        ll b=-n;
        ans=max(ans,min(cost+b*l,cost+b*r));
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