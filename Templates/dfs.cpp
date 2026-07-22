#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define yes cout << "YES"
#define no cout << "NO"
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define print(x) cout << (x)
#define printv(v) do { for (auto &elem : v) cout << elem << " "; } while(0)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const ll MOD = 998244353;

vi dfs;

void helper(int node,vi &vis,vvi &adj){
    vis[node]=1;
    dfs.pb(node);
    for(auto &it:adj[node]){
        if (!vis[it]){
            helper(it,vis,adj);
        }
    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n+1,0);
    vis[0]=1;
    vis[1]=1;
    helper(1,vis,adj);
    printv(dfs);
}

int main(){
    fastio;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}