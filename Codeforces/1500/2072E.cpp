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
distance would be the same when either 
x==x or y==y for any 2 coordinates
*/

int comb(int n){
    return (n*(n-1))/2;
}

void solve(){
    int k;
    cin>>k;
    vvi ans;
    int curX=0,curY=0;
    while(k){
        int cnt=0;
        while(comb(cnt+1) <= k){
            cnt++;
        }
        for(int i=0;i<cnt;i++){
            ans.pb({curX,curY++});
        }
        curX++;
        k-=comb(cnt);
    }
    print(ans.size());
    print(endl);
    for(auto &pt:ans){
        printv(pt);
        print(endl);
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