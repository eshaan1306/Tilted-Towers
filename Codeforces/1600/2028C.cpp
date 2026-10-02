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

int helper(vi &suffCnt,int req){
    int low = 0, high = suffCnt.size()-1;
    int res = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if (suffCnt[mid] >= req){
            res = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return res;
}

void solve(){
    int n,m;
    ll v;
    cin>>n>>m>>v;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //first lets check if its even possible 
    int cnt = 0;
    ll cur = 0;
    ll tol = 0;
    for(int i=0;i<n;i++){
        cur += a[i];
        if (cur >= v){
            cnt++;
            cur = 0;
        }
        tol += a[i];
    }
    if (cnt < m){
        print(-1);
        return;
    }
    vi prefCnt(n+1,0);
    cnt = 0, cur = 0;
    for(int i=1;i<=n;i++){
        cur += a[i-1];
        if (cur >= v){
            cnt++;
            prefCnt[i] = cnt;
            cur = 0;
        }
        else{
            prefCnt[i] = cnt;
        }
    }
    vi suffCnt(n+1,0);  
    cnt = 0, cur = 0;
    for(int i=n-1;i>=0;i--){
        cur += a[i];
        if (cur >= v){
            cnt++;
            suffCnt[i] = cnt;
            cur = 0;
        }
        else{
            suffCnt[i] = cnt;
        }
    }
    vl pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + a[i-1];   
    }
    vl suff(n+1,0);
    for(int i=n-1;i>=0;i--){
        suff[i] = suff[i+1] + a[i];     
    }
    //now we will check over all positions and try to find a cut
    ll ans = 0;
    for(int i=0;i<=n;i++){
        //we will check if we can make a cut here
        ll req = max(m - prefCnt[i],0);
        //now we binary search over the suffCnt array
        int indx = helper(suffCnt,req);
        //hence its possible
        if (indx != -1){
            ll left = pref[i];
            ll right = suff[indx];
            ll rem = tol - left - right;
            ans = max(ans,rem);
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
