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
just brute force it 
*/

int helper(vi& a, int k){
    int n = a.size();
    vi present(n+1,0);
    vi vals;
    int mex = 0;
    for (int i=0;i<n;i++){
        present[a[i]] = 1;
        while (mex <= n && present[mex]){
            mex++;
        }
        vals.push_back(mex);
    }
    sort(vals.rbegin(), vals.rend());
    return vals[k - 1];
}

void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int best = helper(a, k);
    int ansI = -1, ansJ = -1;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            swap(a[i], a[j]);
            int cur = helper(a, k);
            swap(a[i], a[j]);
            if (cur > best){
                best = cur;
                ansI = i + 1;
                ansJ = j + 1;
            }
        }
    }
    if (ansI == -1){
        print(-1);
        return;
    }
    cout<<ansI<<" "<<ansJ;
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