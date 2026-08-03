#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define yes cout << "YES"
#define no cout << "NO"
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
#define printv(v) do { for (auto &elem : v) cout << elem << " "; } while(0)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const ll MOD = 1000000007;
#define msi multiset<int>
#define msl multiset<long long>
#define si set<int>
#define sl set<long long>
#define mpii map<int, int>
#define mpll map<ll, ll>
#define mpsi map<string, int>
#define mpis map<int, string>
#define umpii unordered_map<int, int>
#define umpll unordered_map<ll, ll>
#define umpsi unordered_map<string, int>

/* 
not interval partitioning 
no segment in group 1 should intersect 
a segment in group 2 and vice versa
so intervals should be like 
group 1:      group 2:
  ...  ..       ... ...
... ... ...      ...  .... 
basically like a split
so max(r) of group 1<min(l)
sort with increasing start time
track max r, if anywhere l>r we have an answer
*/

void solve(){
    int n;
    cin>>n;
    vvi v(n);
    vi ans(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        vi temp={l,r,i};
        v[i]=temp;
    }
    sort(all(v));
    int maxr=v[0][1];
    int indx=-1;
    for(int i=1;i<n;i++){
        if (v[i][0]>maxr){
            indx=i;
            break;
        }
        else{
            maxr=max(maxr,v[i][1]);
        }
    }
    if (indx==-1){
        print(-1);
        return;
    }
    for(int i=0;i<indx;i++){
        ans[v[i][2]]=1;
    }
    for(int i=indx;i<n;i++){
        ans[v[i][2]]=2;
    }
    printv(ans);
}

int main(){
    fastio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
