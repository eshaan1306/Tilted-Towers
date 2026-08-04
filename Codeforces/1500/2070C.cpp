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
minimize the maximum, maybe bs
if we can do in <=mid, then we return true
else we return false and do the bs on that 
so we take care for each ai > mid 
if ai > mid is red then dont change it if not change it 
so basically those are like "barriers" 
just check if excluding those "barriers" we can select <= k 
subsegments
*/

bool check(vi &a,int n,int k,string &s,int mid){
    //1:change , 0:dont change, -1:ignore
    vi state(n,-1);
    for(int i=0;i<n;i++){
        if (a[i]>mid){
            if (s[i] == 'B'){
                state[i]=1;
            }
            else{
                state[i]=0;
            }
        }
    }
    int i=0;
    int cnt=0;
    while(i<n){
        if (state[i] != 1){
            i++;
            continue;
        }
        cnt++;
        int j=i+1;
        while(j<n && (state[j] != 0)){
            j++;
        }
        i=j;
    }
    return cnt<=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int low=0,high=1e9;
    int ans=1e9;
    while(low<=high){
        int mid = low + (high-low)/2;
        if (check(a,n,k,s,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
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