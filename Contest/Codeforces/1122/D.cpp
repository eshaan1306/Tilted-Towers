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
observation 1
if anywhere
a[i] > a[i+1]
then either both of them increment together
or nothing 
or only a[i] does, either case, they cant be equal 
observation 2
i thik if i have a subarray of non decreasing elements 
with total sum S, let's say number of element are n 
then I can definitely in some way or the other all of those equal
given S // n
maybe the condition of array being non decreasing is wrong 
okay lets say the answer is something like this 
[ random ass shit ][ answer ][random ass shit]
if i was to move [answer] before [random ass shit #1]
nothing would change it was just be 
[answer - len(ras)][ras][ras]
that means i want to look at the question in a way that 
if i were to in some means bring our answer block in front 
that wouldnt change anything
observation 
if lets say answer is 
a[i1] a[i2] a[i3]
and they are the first 3 indexes
a[i1] == a[i2] (at that moment)
but thing is w ehave subtracted how far they are from their current
index
a[i1] - i1 similarly a[i2] - i2
also a[i1] -i1 would have incremented a[i2] -i2 by 1!!!
so we should have consecutive numbers after subtracting their
indexes
*/

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i] -= i;
    }
    sort(all(a));
    int ans = 1;
    int len = 1;
    int prev = a[0];
    for(int i=1;i<n;i++){
        if (a[i] == prev){
            continue;
        }
        if (a[i] == prev+1){
            len++;
            ans=max(ans,len);
        }
        else{
            len=1;
        }
        prev = a[i];
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