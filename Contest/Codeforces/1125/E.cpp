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
the only observation is if you take a cross
then you have to always travel in a zig zag
order, if you take |
then its like a subproblem division
*/

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll cur=0;
    // a1 -> b1 -> a2 -> b2 -> ... -> an -> bn
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            cur += 2;
        }
        else{
            cur++;
        }
        if(i < n-1){
            if(b[i] == a[i+1]){
                cur += 2;
            }
            else{
                cur++;
            }
        }
    }
    ll ans = cur;
    for(int i=n-2;i>=0;i--){
        // remove a[i] -> b[i]
        if(a[i] == b[i]){
            cur -= 2;
        }
        else{
            cur--;
        }
        // other movement preserved as it would be used
        // add a[i] -> b[i+1]
        if(a[i] == b[i+1]){
            cur += 2;
        }
        else{
            cur++;
        }
        ans=max(ans,cur);
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