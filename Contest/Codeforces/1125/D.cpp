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

bool check(vl &a,vl &b,vl &c,ll k, ll mid){
    ll n = a.size();
    for(int i=0;i<n;i++){
        ll cur = a[i] + b[i] + c[i];
        // already possible 
        if (cur >= mid){
            continue;
        }
        //we are doomed
        if (a[i] == b[i] && b[i] == c[i]){
            return false;
        }
        ll req = mid - cur;
        //all negatives
        //this means we first have to decrease, then increase
        if (a[i] <= b[i] && b[i] <= c[i]){
            //we have to decrease either b or c with this much
            ll del = min(abs(a[i]-b[i]),abs(b[i]-c[i])) + 1;
            req += del;
            //also total sum decreased by del so need to factor that too
            req += del;
        }
        if (req > k){
            return false;
        }
        k -= req;
    }
    return true;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vl a(n),b(n),c(n);
    ll low = LLONG_MAX,high = LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        low = min(low, a[i] + b[i] + c[i]);
    }
    ll ans = low;
    high = low + k;
    while(low <= high){
        //check if this is possible
        ll mid = low + (high-low)/2;
        ll flag = check(a,b,c,k,mid);
        if (flag){
            ans = mid;
            low = mid +1;
        }
        else{
            high = mid-1;
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