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
n == 8
_ _ _ _ 
at every bit, the count of 1 should be 2 
need to reduce f(a)
1 2 4 8 == bitwise xor 15
1 2 4 8 1 2 4 8
n == 6
1 1 0
1 0 0, 0 1 0, 0 0 1,
4 2 1 4 2 1
for 2*bits length, answer is 
2b - 1
b+1
2(b+1) - 2
2b + 2 - 2 == 2
2(b+2) - 3 
2b + 1
2 
1 2 1 2 : 4 : 3
1 2 1 2
n == 4
1 2 4 1 2 4 : 6 : 5
1 2 4 1 2 4 1 : 7 : 6
1 2 4 1 2 4 1 2 : 8 :
*/

void solve(){
    int n;
    cin>>n;
    int bits = 1;
    int temp = n;
    while (temp > 1){
        bits++;
        temp/=2;
    }
    int len = (1<<(bits+1)) - 1;
    vi ans(len);
    int m = (1<<bits);
    int prev = 0;
    for (int i = 1; i <= len; i++) {
        int x = i % m;
        int curr = x ^ (x >> 1); 
        ans[i-1] = prev^curr;
        prev = curr;
    }
    print(ans.size());
    cout<<"\n";
    printv(ans);
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