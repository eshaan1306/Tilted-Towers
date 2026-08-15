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
since the movement costs |i-j| which is the 
difference bw indexes, if i am lets say at index i 
I only care about the first index to its right to which its connected
using both of the colours
so if we start from the far right 
maybe using a dsu we can store this info of reachability
but wont give the cost
since there are only 4 colours what we can do is we can brutely check
because the number of jumps would only be atmost 3 !!!! 
*/

class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if (node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbyRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if (ulp_u==ulp_v) return;
        if (rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if (rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if (ulp_u==ulp_v) return;
        if (size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else if (size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

bool isCommon(string &s,string &t){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if (s[i] == t[j]){
                return true;
            }
        }
    }
    return false;
}

int nearestLeft(vi &positions,int x){
    int low=0,high=positions.size()-1,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (positions[mid]<x){
            ans=positions[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int nearestRight(vi &positions,int x){
    int low=0,high=positions.size()-1,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (positions[mid]>x){
            ans=positions[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> portals(n);
    for(int i=0;i<n;i++){
        cin>>portals[i];
    }
    unordered_map<char,int> mp;
    mp['B']=-1;
    mp['R']=-1;
    mp['G']=-1;
    mp['Y']=-1;
    DisjointSet ds(n);
    unordered_map<string,vector<int>> p;
    //hardcoding neighbours
    unordered_map<string,vector<string>> neighbours;
    neighbours["BG"] = {"BR", "BY", "GR", "GY"};
    neighbours["BR"] = {"BG", "BY", "GR", "RY"};
    neighbours["BY"] = {"BG", "BR", "GY", "RY"};
    neighbours["GR"] = {"BG", "BR", "GY", "RY"};
    neighbours["GY"] = {"BG", "BY", "GR", "RY"};
    neighbours["RY"] = {"BR", "BY", "GR", "GY"};
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            if (mp[portals[i][j]] != -1){
                ds.unionbySize(i,mp[portals[i][j]]);
            }
            mp[portals[i][j]]=i;
        }
        p[portals[i]].pb(i);
    }
    for(auto &[type,positions]:p){
        reverse(all(positions));
    }
    for(int iter=0;iter<q;iter++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if (ds.findUpar(x) != ds.findUpar(y)){
            cout<<-1<<endl;
            continue;
        }
        if (isCommon(portals[x],portals[y])){
            cout<<abs(x-y)<<endl;
            continue;
        }
        //either on the currents left or on the current right
        //take the closest 
        int ans=INT_MAX;
        for(string &type:neighbours[portals[x]]){
            if (!isCommon(type,portals[y])) continue;
            int l=nearestLeft(p[type],x);
            int r=nearestRight(p[type],x);
            if (l!=-1) ans=min(ans,abs(x-l)+abs(l-y));
            if (r!=-1) ans=min(ans,abs(x-r)+abs(r-y));
        }
        if (ans==INT_MAX){
            ans=-1;
        }
        cout<<ans<<endl;
    }
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
