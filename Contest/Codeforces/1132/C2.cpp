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
gcd(a,c-a) = gcd(a,c)
or i can say 
gcd(a,x) = gcd(a,x+a)
so it basically becomes, we can jump from
1 number to the other, iff they are coprime
*/

ll gcd(ll a,ll b){
    if (b == 0){
        return a;
    }
    return gcd(b,a%b);
}

void solve(){
    ll a,b;
    cin>>a>>b;
    if (a == b){
        print(0);
        return;
    }
    if (gcd(a,b) == 1){
        print(1);
        cout<<"\n";
        print(b-a);
        return;
    }
    /*
    here is the trick right
    for any value till 1e5, the max diff bw 2 primes
    is 72, so if I satrt from a and go till a+72, I will definetly find a number which is a prime
    so my answer will be 2, as i can go from a to that prime and then to b
    if b is < a+72, then we can just do a dp
    */
    for(ll i=a+1;i<=min(a+72,b);i++){
        ll gcd1 = gcd(a,i);
        ll gcd2 = gcd(i,b);
        if (gcd1 == 1 && gcd2 == 1){
            print(2);
            cout<<"\n";
            cout<<i-a<<" "<<b-i;
            return;
        }
    }
    vl dp(b-a+1,1e9);
    dp[0] = 0;
    vl val(b-a+1,0);
    for(int i=1;i<=b-a;i++){
        ll num1 = a + i;
        for(int j=0;j<i;j++){
            ll num2 = a + j;
            if (gcd(num1,num2) == 1){
                if (dp[j] + 1 < dp[i]){
                    dp[i] = dp[j] + 1;
                    val[i] = j;
                }
            }
        }
    }
    print(dp[b-a]);
    cout<<"\n";
    vl nums;
    int indx = b-a;
    while(indx > 0){
        nums.pb(a + indx);
        indx = val[indx];
    }
    nums.pb(a);
    reverse(all(nums));
    vl ans;
    for(int i=1;i<nums.size();i++){
        ans.pb(nums[i] - nums[i-1]);
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