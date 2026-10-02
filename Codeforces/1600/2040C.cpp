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
[1 2 3] : 1 * 3 = 3
[2 1 3] : 2 *2 = 4 hence 1 cannot be in middle
[2 3 1 ] : 3 * 1 = 3
hence we will first consider the n length array 
place 1 either on the left, or on the right 
then we will consider the n-1 length array
place 2 either on the left, or on the right
... and so on
so total ways are 2 ^ (n-1)
*/

void solve(){
    ll n,k;
    cin>>n>>k;
    ll tol = 1;
    //store power of 2s
    vl pow2;
    pow2.pb(1);
    for(int i=0;i<n-1;i++){
        tol*=2;
        pow2.pb(tol);
        if (tol > k){
            break;
        }
    }
    //check if possible
    if (tol < k){
        print(-1);
        return;
    }
    vl ans(n);
    int left = 0, right = n-1;
    ll cur = 1;
    ll rem = n;
    while(left < right){
        //placing on the left
        /*
        so lets say we have x positions
        we placed it on the left
        so remaining are x-1 positions
        so total valid ways there are 2^(x-2)
        */ 
        if (rem - 2 < 0 || rem-2 >= pow2.size()){
            ans[left] = cur;
            left++;
            rem--,cur++;
            continue;
        }
        ll pos = pow2[rem-2];
        //we place it on the left only
        if (pos >= k){
            ans[left] = cur;
            left++;
        }
        else{
            ans[right] = cur;
            right--;
            k -= pos;
        }
        rem--,cur++;
    }
    if (left == right){
        ans[left] = cur;
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
