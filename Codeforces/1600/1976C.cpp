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
    int n,m;
    cin>>n>>m;
    int sz = n+m+1;
    vl a(sz),b(sz);
    for(int i=0;i<sz;i++){
        cin>>a[i];
    }
    for(int i=0;i<sz;i++){
        cin>>b[i];
    }
    vl ans(sz);
    if(n==0){
        ll tol=0;
        for(int i=0;i<sz;i++){
            tol+=b[i];
        }
        for(int i=0;i<sz;i++){
            ans[i]=tol-b[i];
        }
        printv(ans);
        return;
    }
    if(m==0){
        ll tol=0;
        for(int i=0;i<sz;i++){
            tol+=a[i];
        }
        for(int i=0;i<sz;i++){
            ans[i]=tol-a[i];
        }
        printv(ans);
        return;
    }
    int last=sz-1;
    vi progFlag(sz,0);
    int prog=0;
    int test=0;
    ll tol=0;
    int forcedIdx=-1;
    for(int i=0;i<last;i++){
        if(a[i]>b[i]){
            if(prog<n){
                progFlag[i]=1;
                prog++;
                tol+=a[i];
            }
            else{
                progFlag[i]=0;
                test++;
                tol+=b[i];

                if(forcedIdx==-1){
                    forcedIdx=i;
                }
            }
        }
        else{
            if(test<m){
                progFlag[i]=0;
                test++;
                tol+=b[i];
            }
            else{
                progFlag[i]=1;
                prog++;
                tol+=a[i];
                if(forcedIdx==-1){
                    forcedIdx=i;
                }
            }
        }
    }
    ans[last]=tol;
    for(int i=0;i<last;i++){
        ll curr=tol;
        if(progFlag[i]){
            curr-=a[i];
        }
        else{
            curr-=b[i];
        }
        if(forcedIdx!=-1 && i<forcedIdx && progFlag[i]!=progFlag[forcedIdx]){
            if(progFlag[forcedIdx]){
                curr-=a[forcedIdx];
                curr+=b[forcedIdx];
                curr+=a[last];
            }
            else{
                curr-=b[forcedIdx];
                curr+=a[forcedIdx];
                curr+=b[last];
            }
        }
        else{
            if(progFlag[i]){
                curr+=a[last];
            }
            else{
                curr+=b[last];
            }
        }
        ans[i]=curr;
    }
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