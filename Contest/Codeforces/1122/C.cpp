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
solve upon the first 1 we would keep
*/

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    //special case
    if (s[0] == '1'){
        int ans = 0;
        for(int i=1;i<n;i++){
            ans += (s[i]=='0');
        }
        print(ans);
        return;
    }
    //first 1, this is our pivot/wall
    int indx = -1;
    for(int i=0;i<n;i++){
        if (s[i] == '1'){
            indx = i;
            break;
        }
    }
    //already all zeroes
    if (indx == -1){
        print(0);
        return;
    }
    //number of 1s in pre
    vi pref(n+1,0);
    //number of 0s in suffix
    vi suff(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + (s[i]=='1');
    }
    for(int i=n-1;i>=0;i--){
        suff[i] = suff[i+1] + (s[i]=='0');
    }
    int ans = n; 
    for(int i=indx;i<=n;i++){
        int cur = pref[i]+suff[i];
        ans = min(ans,cur);
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