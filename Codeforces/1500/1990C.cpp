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
    int n;
    cin>>n;
    vi a(n);
    ll sum = 0;
    map<int,int> freq;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += 1LL*a[i];
    }
    vector<int> pre(n,0);
    freq[a[0]]++;
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1];
        freq[a[i]]++;
        if (freq[a[i]] >= 2){
            pre[i] = max(pre[i],a[i]);
        }
    }
    /*
    basically array would be firstly
    increasing 
    [0,0,0,,,..1,1,1,1,1...,2,2,2,2,2,,,...3,,3333,33]
    [0 1 1 1 2 2 3 3 3]
    [0 0 1 1 1 2 2 3 3]
    */
    freq.clear();
    vector<int> pre2(n,0);
    freq[pre[0]]++;
    for(int i=1;i<n;i++){
        sum += pre[i];
        pre2[i] = pre2[i-1];
        freq[pre[i]]++;
        if (freq[pre[i]] >= 2){
            pre2[i] = max(pre2[i],pre[i]);
        }
    }
    int indx = -1;
    for(int i=0;i<n;i++){
        if (pre2[i] != 0){
            indx = i;
            break;
        }
    }
    if (indx != -1){
        for(int i=indx;i<n;i++){
            sum += 1LL*pre2[i]*(n-i);
        }
    }
    print(sum);
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