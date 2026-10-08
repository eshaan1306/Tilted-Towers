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
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi p(n,0);
    stack<int> stk;
    for(int i=0;i<n;i++){
        if (s[i] ==  '1'){
            stk.push(i);
        }
        else if (s[i] ==  '2'){
            if (!stk.empty()){
                int indx = stk.top();
                stk.pop();
                p[indx] = 1;
            }
            else{
                p[i] = 1;
            }
        }
        else{
            p[i] = 1;
        }
    }
    vi ans;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if (!p[i]){
            ans.pb(i+1);
            cnt++;
        }
    }
    print(cnt);
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