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
1 2 4 8
0000
0001
0010
0011
0100
0101
0110 
0111
1000
1001
let the msb of n be b
then k would always be 2^b - 1
*/

int helper(int n){
    if (n%4 == 0){
        return n;
    }
    else if (n%4 == 1){
        return 1;
    }
    else if (n%4 == 2){
        return n+1;
    }
    else{
        return 0;
    }
}

void solve(){
    int n;
    cin>>n;
    int b = -1;
    int temp = n;
    while(temp){
        b++;
        temp >>= 1;
    }
    vi cnt(b+1,0);
    for(int i=0;i<=b;i++){
        for(int x=1;x<=n;x++){
            if (x & (1<<i)){
                cnt[i]++;
            }
        }
    }
    vi d(n,0);
    temp = (1<<b);
    d[temp-1] = 1;
    cnt[b]--;
    for(int i=b;i>0;i--){
        if (!(cnt[i]&1)){
            int num = (1<<(i-1));
            d[num-1] = 1;   
            cnt[i]++;
            cnt[i-1]--;
        }
    }
    printv(d);
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