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

*/

void solve(){
    int n,m;
    cin>>n>>m;
    vvi a(n,vi(m));
    vvi b(n,vi(m));
    vvi indexes_a(n*m,vi(2));
    vvi indexes_b(n*m,vi(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]--;
            indexes_a[a[i][j]][0] = i;
            indexes_a[a[i][j]][1] = j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
            b[i][j]--;
            indexes_b[b[i][j]][0] = i;
            indexes_b[b[i][j]][1] = j;
        }
    }
    if (n == 1 || m == 1){
        yes;
        return;
    }
    vi convertRow(n,-1);
    vi convertCol(m,-1);
    //check row mapping
    for(int cand=0;cand<n*m;cand++){
        int row1 = indexes_a[cand][0];
        int row2 = indexes_b[cand][0];
        if (convertRow[row1] == -1){
            //good
            convertRow[row1] = row2;
        }
        else if (convertRow[row1] != row2){
            no;
            return;
        }
    }
    //check col mapping
    for(int cand=0;cand<n*m;cand++){
        int col1 = indexes_a[cand][1];
        int col2 = indexes_b[cand][1];
        if (convertCol[col1] == -1){
            //good
            convertCol[col1] = col2;
        }
        else if (convertCol[col1] != col2){
            no;
            return;
        }
    }
    yes;
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