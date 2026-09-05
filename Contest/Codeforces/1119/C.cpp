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
the ends should be 1 only 
then we can maybe rely our answer on the prev element
if its 0, go with 0, if its 1, go with 0
okay so i think we cangeneralize the end points to be 1
so we have to get 1 as early as possible from the ends
*/

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int left=0,right=n-1;
    for(int i=0;i<n;i++){
        if (a[i]==-1){
            a[i]=1;
            left=i;
            break;
        }
        else if (a[i]==1){
            left=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if (a[i]==-1){
            a[i]=1;
            right=i;
            break;
        }
        else if (a[i]==1){
            right=i;
            break;
        }
    }
    for(int i=left+1;i<right;i++){
        if (a[i] == -1){
            a[i]=0;
        }
    }
    printv(a);
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