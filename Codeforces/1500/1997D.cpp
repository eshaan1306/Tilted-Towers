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
basicaly for each subtre, we find the minimum element 
if that minimum element is the root itself, we try to increase
to we have an equal distribution
*/

int dfs(int u, vvi &adj, vi &vis, vi &a){
    vis[u]=1;
    int mini = INT_MAX;
    for(auto &v:adj[u]){
        if (!vis[v]){
            int val = dfs(v,adj,vis,a);
            mini = min(mini,val);
        }
    }
    if (u == 0){
        return mini;
    }
    //last node
    if (mini == INT_MAX){
        return a[u];
    }
    if(a[u] >= mini){
        return mini;
    }
    return (a[u] + mini)/2;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi p(n-1);
    vvi adj(n);
    for(int i=0;i<n-1;i++){
        cin>>p[i];
        adj[p[i]-1].push_back(i+1);
    }
    vi vis(n,0);
    int val = dfs(0,adj,vis,a);
    int ans = a[0]+val;
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