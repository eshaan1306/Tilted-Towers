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
we need to take care of the difference
between top and the bottom row
because equal number in them would complement each other
by jumping vertically
therefore we can make sort of pairs for 2 frogs
which would complement their jump
if 
f
f
they both complement
if 
f f
they complement
if 
f
 f
these complement
if we have
f f
f
then 1 would remain
that means we can pair them up as we move
which makes them dependent on their PARITY !!!!
*/

void solve(){
    int n;
    cin>>n;
    vector<vector<char>> grid(2,vector<char>(n));
    int cnt = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            cnt += (grid[i][j] == 'f');
        }
    }
    print(cnt&1);
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