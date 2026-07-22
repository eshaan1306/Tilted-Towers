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

/*
KAHNS ALGORITHM
*/

void solve(){
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    vi indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto &it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if (indegree[i]==0) q.push(i);
    }
    vi ans;
    while(q.size()){
        int node=q.front();
        q.pop();
        ans.pb(node);
        for(auto &it:adj[node]){
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    //if size<n then cycle exists
    printv(ans);
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