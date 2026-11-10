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
when n is even, its a no blinder to select n+1
we will then have 1,n ; 2,n-1,.. and we would colour everything as black
when n is odd, one vertex would be left, so we will choose value such that we are
able to colour some gray
n = 7
if k = 7
[1,6] [2,5] [3,4] [0,7]
if k = 8
[1,7] [2,6] [3,5] [4,0]
if k = 9
[1,8] [2,7] [3,6] [4,5],[5,4],[6,3],[7,2]
k = 10
[1,9] [2,8] [3,7] [4,6] [5,5] [6,4] [7,3]
so we can go till n+2 only
k = 6
[1,5] [2,4] [3,3] [4,2] [5,1] [6,0] [7,-1]
okay so k can only be in the range [n,n+2]
so we can sort of just check
*/

void solve(){
    int n;
    cin>>n;
    vvi adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (!(n&1)){
        print(n+1);
        return;
    }
    vi cands = {n,n+1,n+2};
    for(auto &k:cands){
        set<pair<int,int>> st;
        vector<int> present(n+1,0);
        for(int i=1;i<=n;i++){
            int u = i;
            int v = k - u;
            int mini = min(v,u);
            int maxi = max(v,u);
            if (mini >=1 && maxi <= n && u != v){
                st.insert({mini,maxi});
                present[mini] = 1;
                present[maxi] = 1;
            }
        }
        int missing = -1;
        for(int i=1;i<=n;i++){
            if (!present[i]){
                missing = i;
                break;
            }
        }
        queue<pair<int,int>> q;
        vi vis(n+1,0);
        vis[missing] = 1;
        vi segment(n+1,-1);
        for(int i=0;i<adj[missing].size();i++){
            int v = adj[missing][i];
            q.push({i,v});
            vis[v] = 1;
            segment[v] = i;
        }
        while(!q.empty()){
            auto [seg,u] = q.front();
            q.pop();
            for(auto &v:adj[u]){
                if (!vis[v]){
                    vis[v] = 1;
                    segment[v] = seg;
                    q.push({seg,v});
                }
            }
        }
        for(auto &p:st){
            int u = p.first;
            int v = p.second;
            if (segment[u] != segment[v]){
                print(k);
                return;
            }
        }
    }
    print(n);
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