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
i think there are serveral cases
if the candidate i is already the winner then 0 
if not then there are 2 cases roughly 
[--left--ai--right--]
case i) let the real winner lie to its left
then simply the answer would be the number of candidates to its left
case ii) the real winner would lie to its right
then answer would atleast be the number on its left + on top of that
we would need to calculate the extra to remove from the right
hold on bruh, just remove the maximum from the right, so 1 extra operation
*/

void solve(){
    int n;
    ll c;
    cin>>n>>c;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //real winner value
    int realIndx = 0;
    ll maxi = a[0] + c;
    for(int i=1;i<n;i++){
        if (a[i] > maxi){
            maxi = a[i];
            realIndx = i;
        }
    }
    vl pref(n+1,c);
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + a[i-1];
    }
    vl suffMax(n+1,-1);
    for(int i=n-1;i>=0;i--){
        suffMax[i] = max(suffMax[i+1],a[i]);
    }
    vi ans(n);
    for(int i=0;i<n;i++){
        if (a[i] == maxi){
            if (i == realIndx){
                ans[i] = 0;
            }
            else{
                //realIndx < i
                ans[i] = i;
            }
        }
        else{
            //remove everything from left
            ll left = pref[i+1];
            if (left < suffMax[i+1]){
                ans[i] = i+1;
            }
            else{
                ans[i] = i;
            }
        }
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