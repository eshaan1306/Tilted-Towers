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
from 1 plank: we get 3 of 18, 2 of 21 and 2 of 25
we cant group all of them together 
so the options are to 
go individually 
then pair (18,21) -> here options are (1 18, 2 21) and (2 18, 1 21)
pair (21,25)-> this one takes n+ceil(n/3)
pair (18,25)-> this one seems bs it would take total of n+ceil(n/2)
now can we just simulate them to get the minimum?
or there are some calculations
18,25 eliminated
1 18, 2 21 takes
ceil(n/2)+ceil(n/2)+ceil(n/4) approx 
2 18, 1 21 takes 
ceil(n/2)+ceil(n/2)+ceil(n/4) approx 
i think the same only 
first one sounds better as no remaining lol 
i think they would perform 
i think this would beat n + ceil(n/3) also 
okay so optimum would be 
21,21,18 first
then 25,25 
then remaining 18
*/

void solve(){
    int n;
    cin>>n;
    int ans=((n+5)/6) + n;
    print(ans);
}

int main(){
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}