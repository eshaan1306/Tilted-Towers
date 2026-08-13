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
so for each row we have 2 options
either we remove all the elements there
so the answer would be m
or from each row below, we take the max elements
until our total reaches the value specified
so my answer lies between 1 and m 
*/

//nmlog(nm)
bool check(vvl &a,vl &v,int mid){
    int n = a.size();
    int m = a[0].size();
    priority_queue<ll> pq;
    //n
    for(int i=n-1;i>=0;i--){
        //mlog(nm)
        for(int j=0;j<m;j++){
            pq.push(a[i][j]);
        }
        ll val=0;
        vl rem;
        //m
        for(int iter=0;iter<mid;iter++){
            val += pq.top();
            rem.pb(pq.top());
            pq.pop();
        }
        if (val>=v[i]){
            return true;
        }
        //mlog(nm)
        for(int j=0;j<mid;j++){
            pq.push(rem[j]);
        }
    }
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vl v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vvl a(n,
        vl (m)
    );
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     sort(all(a[i]));
    // }
    int low=1,high=m-1;
    int ans=m;
    //log(m)
    while(low<=high){
        int mid = low + (high-low)/2;
        //nmlog(nm)
        bool flag = check(a,v,mid);
        if (flag){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
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