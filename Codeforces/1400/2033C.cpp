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
    for(int i=0;i<n;i++){
        cin>>a[i];  
    }
    if (n==1){
        print(0);
        return;
    }
    vvi dp(n/2,vi(2,0));
    if ((n&1)){
        int indx = (n/2)-1;
        dp[indx][0] = (a[indx]==a[n/2]) + (a[indx+2]==a[n/2]);
        dp[indx][1] = (a[indx]==a[n/2]) + (a[indx+2]==a[n/2]);
    }
    else{
        int indx = (n/2)-1;
        dp[indx][0] = (a[indx]==a[indx+1]);
        dp[indx][1] = (a[indx]==a[indx+1]);
    }
    for(int i=(n/2)-2;i>=0;i--){
        for(int j=0;j<2;j++){
            int x=a[i];
            int y=a[n-i-1];
            int z=a[i+1];
            int w=a[n-i-2];
            //no swap
            if (!j){
                //no swap for the next
                int cnt=0;
                int mini=INT_MAX;
                if (x==z){
                    cnt++;
                }
                if (y==w){
                    cnt++;
                }
                mini=min(mini,cnt+dp[i+1][0]);
                //swap for the next
                cnt=0;
                if (x==w){
                    cnt++;
                }
                if (y==z){
                    cnt++;
                }
                mini=min(mini,cnt+dp[i+1][1]);
                dp[i][j]=mini;
            }
            //swap
            else{
                int cnt=0;
                int mini=INT_MAX;
                if (y==z){
                    cnt++;
                }
                if (x==w){
                    cnt++;
                }
                mini=min(mini,cnt+dp[i+1][0]);
                //swap for the next
                cnt=0;
                if (y==w){
                    cnt++;
                }
                if (x==z){
                    cnt++;
                }
                mini=min(mini,cnt+dp[i+1][1]);
                dp[i][j]=mini;
            }
        }
    }
    print(min(dp[0][0],dp[0][1]));
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