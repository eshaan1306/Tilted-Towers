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
firstly parity would never change, so we have to
work upon the elements of the same parity
odd number would be stuck at 1
even number would rotate around 0 and 2
so first we clearly have the case where the answer is
the number of odd numbers
for even numbers, we can calculate in how many operations would it reach 0
which would be just the a[i]/2
after that all the same parity ones can fixate at either 0 or 2 always
*/

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];  
    }
    int oddCount=0;
    vi even;
    for(int i=0;i<n;i++){
        if (a[i]&1){
            oddCount++;
        } 
        else {
            even.pb(a[i]);
        }
    }
    for(int i=0;i<even.size();i++){
        even[i]/=2;
        even[i]&=1;
    }
    int cntOdd=0,cntEven=0;
    for(auto &x:even){
        if (x&1){
            cntOdd++;
        }
        else{
            cntEven++;
        }
    }
    int ans = max(oddCount, max(cntOdd,cntEven));
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