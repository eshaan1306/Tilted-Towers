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
sort of brute force 
basically for each number, we will look
at its half 
lets start with 2^30
2^29,2^29 i)
2^28, 2^28 ii) 
1 we cannot make 
2 is (1,1) so 1 move
3 is (1,2) in which 2 is 1 move so 2 moves
4 is (2,2) which is 1 + 1 + 1 so 3 moves
so basically for each element we need (worst case) n-1 moves
*/

void solve(){
    int n,m;
    cin>>n>>m;
    vl a(n),b(m);
    msl st;
    //sum never changes
    ll sum = 0;
    priority_queue<int> pq1,pq2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
        pq1.push(a[i]);
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        sum -= b[i];
        pq2.push(b[i]);
    }
    if (sum != 0){
        no;
        return;
    }
    //while we have some elements
    while(!pq1.empty() && !pq2.empty()){
        int cur = pq1.top();
        int target = pq2.top();
        pq1.pop();
        pq2.pop();
        if (cur == target){
            //very good
        }
        else if (cur > target){
            //not possible, as cur is only added
            no;
            return;
        }
        else{
            pq2.push(target/2);
            pq2.push(target - target/2);
            pq1.push(cur);
        }
    }
    if (pq1.empty() && pq2.empty()){
        yes;
        return;
    }
    no;
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