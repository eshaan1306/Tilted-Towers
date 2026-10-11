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
the only optimization is
we store only 7 prime numbers
because one of the numbers can have more than
those many
*/

const ll maxi = 1000000;
vl sieve(maxi+1);

void pre(){
    for(int i=0;i<=maxi;i++){
        sieve[i] = i;
    }
    for(ll i=2;i*i<=maxi;i++){
        if(sieve[i] == i){
            for(ll j=i*i;j<=maxi;j+=i){
                if (sieve[j] != j){
                    continue;
                }
                sieve[j] = i;
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //odd prime factors of each element
    vvl ker(n);
    for(int i=0;i<n;i++){
        ll temp = a[i];
        while(temp > 1){
            ll p = sieve[temp];
            ll cnt = 0;
            while(temp % p == 0){
                temp /= p;
                cnt++;
            }
            if(cnt & 1){
                ker[i].pb(p);
            }
        }
    }
    //prefix signatures with at most 7 primes
    map<vl,ll> mpOdd;
    sl odd;
    for(int i=0;i<n;i++){
        for(auto p:ker[i]){
            if(odd.find(p) != odd.end()){
                odd.erase(p);
            }
            else{
                odd.insert(p);
            }
        }
        if(odd.size() <= 7){
            mpOdd[vl(all(odd))]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        auto it = mpOdd.find(ker[i]);
        if(it != mpOdd.end()){
            ans += it->second;
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
    pre();
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}