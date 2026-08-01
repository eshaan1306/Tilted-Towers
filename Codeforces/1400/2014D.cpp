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
    int n,d,k;
    cin>>n>>d>>k;
    vi start(n+2,0),end(n+2,0);
    vi diff(n+2,0);
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        start[l]++;
        end[r+1]++;
    }
    int cntStart=0,cntEnd=0;
    for(int i=1;i<=n;i++){
        start[i]+=start[i-1];
        end[i]+=end[i-1];
    }
    int maxDay=-1,minDay=-1;
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=d;i<=n;i++){
        int cnt = start[i]-end[i-d+1];
        if (mini>cnt){
            minDay=(i-d+1);
            mini=cnt;
        }
        if (maxi<cnt){
            maxDay=(i-d+1);
            maxi=cnt;
        }
    }
    cout<<maxDay<<" "<<minDay;
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