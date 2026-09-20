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
okay every row and column has atleast 1 '0
that we need to change, so our x is not fixed
also since we either go down or right
if we go == D then we are fixing the above row 
if we go == R then we are fixing the left column
so therefore lets say we choose x == 0
then we can fix the value of the row/col we are leaving
and the element at that a[i][j], can become as negtive of the current sum
*/

void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vvl a(n,vl(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vl sumRow(n);
    for(int i=0;i<n;i++){
        ll sum = 0;
        for(int j=0;j<m;j++){
            sum += a[i][j];
        }
        sumRow[i] = sum;
    }
    vl sumCol(m);
    for(int j=0;j<m;j++){
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i][j];
        }
        sumCol[j] = sum;
    }
    int i=0,j=0;
    char last;
    for(auto &ch:s){
        //going right, so fixing the column
        last = ch;
        if (ch == 'R'){
            a[i][j]  = -1*sumCol[j];
            sumRow[i] += a[i][j];
            j++;
        }
        else{
            a[i][j]  = -1*sumRow[i];
            sumCol[j] += a[i][j];
            i++;
        }
    }
    if (last == 'R'){
        a[i][j]  = -1*sumCol[j];
        sumRow[i] += a[i][j];
        j++;
    }
    else{
        a[i][j]  = -1*sumRow[i];
        sumCol[j] += a[i][j];
        i++;
    }
    for(int i=0;i<n;i++){
        printv(a[i]);
        cout<<"\n";
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