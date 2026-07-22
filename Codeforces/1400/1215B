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
#define print(x) cout << (x)
#define printv(v) do { for (auto &elem : v) cout << elem << " "; } while(0)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const ll MOD = 1000000007;
#define msi multiset<int>
#define msl multiset<long long>
#define si set<int>
#define sl set<long long>

/*
we only care about num of -ve integers in the subarray
if we calc total subsegment (n(n+1)/2)
then we calc num of subsegments with odd num of neg numbers
we get the odd neg product
subtract that to total, we get pos
so our question boils down to 

number of subarrays with negative integers==odd
*/

void solve(){
    ll n;
    cin>>n;
    vl v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll total=(n*(n+1))/2;
    ll neg=0;
    ll cntOdd=0,cntEven=1;
    ll cnt=0;
    for(int i=0;i<n;i++){
        if (v[i]<0){
            cnt++;
        }
        if (cnt&1){
            neg+=cntEven;
        }
        else{
            neg+=cntOdd;
        }
        if (cnt&1) cntOdd++;
        else cntEven++;
    }
    print(neg);
    print(" ");
    print(total-neg);
}  

int main(){
    fastio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
