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
#define vs vector<string>
#define print(x) cout << (x)
#define printv(v) do { for (auto &elem : v) cout << elem << " "; } while(0)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define msi multiset<int>
#define msl multiset<long long>
#define si set<int>
#define sl set<long long    >
#define mpii map<int, int>
#define mpll map<ll, ll>
#define mpsi map<string, int>
#define mpis map<int, string>
#define umpii unordered_map<int, int>
#define umpll unordered_map<ll, ll>
#define umpsi unordered_map<string, int>
const ll MOD =1e9+7;

/* 
if i says j is crewmate 
then either i and j both crewmate or both impostor
if i says j is impostor 
then either i is impostor and j is crewmate or vice versa
so this gives an idea of where we can check if this relation 
of two players holding
right so we can also have idea of connected componenets
each component is independent of other 
we will randomly assign some member crewmat/impostor 
we get some count of numbers of impostor and crewmate
max will be the impostor (for both cases)
if at any point we reach disagreement (while building graph or traversal)
we just return -1 
*/

string opposite(string call){
    if (call=="crewmate"){
        return "imposter";
    }
    else{
        return "crewmate";
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<set<pair<int,string>>> adj(n+1);
    bool possible=true;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        string call;
        cin>>call;
        //contradiction
        if (adj[u].find({v,opposite(call)})!=adj[u].end()){
            possible=false;
        }   
        adj[u].insert({v,call});
        adj[v].insert({u,call});
    }
    if (!possible){
        print(-1);
        return;
    }
    int ans=0;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if (!vis[i]){
            /*
            -1: not assigned
            0: crewmate
            1: impostor
            */
            vector<int> assign(n+1,-1);
            queue<int> q;
            q.push(i);
            vis[i]=1;
            //default
            assign[i]=0;
            int cnt0=1,cnt1=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                int assigned=assign[u];
                for(auto &p:adj[u]){
                    int v=p.first;
                    string call=p.second;
                    int toBeAssigned=-1;
                    if (call=="crewmate"){
                        toBeAssigned=assigned;
                    }
                    else{
                        toBeAssigned=!(assigned);
                    }
                    if (!vis[v]){
                        vis[v]=1;
                        assign[v]=toBeAssigned;
                        q.push(v);
                        if (toBeAssigned==0){
                            cnt0++;
                        }
                        else{
                            cnt1++;
                        }
                    }
                    else{
                        if (assign[v]!=toBeAssigned){
                            print(-1);
                            return;
                        }
                    }
                }
            }
            ans+=max(cnt0,cnt1);
        }
    }
    print(ans);
}

int main(){
    fastio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}
