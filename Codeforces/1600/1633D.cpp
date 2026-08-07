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
#define vs vector<string>
#define print(x) cout << (x)
#define printv(v) do { for (auto &elem : v) cout << elem << " "; } while(0)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const ll MOD = 998244353;
#define msi multiset<int>
#define msl multiset<long long>
#define si set<int>
#define sl set<long long    >
#define mpii map<int, int>
#define mpll map<ll, ll>
#define mpsi map<string, int>
#define mpis map<int, string>
#define umpii unordered_map<int, int>
#define umpll unordered_map<ll, ll>
#define umpsi unordered_map<string, int>

/* 
first we have to calculate the min number of steps
required to reach each element
then we can do dp on it, kind of like knapsack 
first part: how to find min steps
so looking at the constraints, bi is <=10^3 and size is also <=10^3
so i think n2 for dp 
and for each element, we can find the smallest number of steps for it
using dp too 
how to build dp for this?
okay so we start from dp[1]=0
for each dp[n]
we iterate from each element 1<=i<=n and take floor
and add to it and see if thats the minimum 
if thats the minimum we add it
its literally dijkstra
wait there are no weights, so we can just do a normal bfs
*/

void solve(){
    int n,k;
    cin>>n>>k;
    vi b(n),c(n);
    for(auto &x:b)cin>>x;
    for(auto &x:c)cin>>x;
    //dp[i]= min steps to reach i
    vi dp1(1e3+1,INT_MAX);
    //base case for 1
    dp1[1]=0;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int el=q.front();
        //total 1e3
        q.pop();
        //max length of loop 1e3
        for(int i=1;i<=el;i++){
            int x=el+(el/i);
            //intmax acts as visited 
            if (x<=1e3 && dp1[x]==INT_MAX){
                dp1[x]=dp1[el]+1;
                q.push(x);
            }
        }
    }
    //total TC for bfs 1e6 thats fine
    /*
    wait k <= 1e6
    cant do nk
    either k or n2
    observation: max vaue in dp1 is only 12!!
    so my upper bound for k is 12*n
    so now it is achievable i can just set k' to 12*n
    this gives TC n^2
    */
//    int maxi=INT_MIN;
//    for(int i=1;i<=1e3;i++){
//     maxi=max(dp1[i],maxi);
//    }
//    //prints 12
//    print(maxi);
    int new_k=12*n;
    //dp[i][j]=max coins till i, using at most j moves
    vvi dp2(n,vi(new_k+1,0));
    //base case, i=0 and k=0
    for(int k=0;k<=new_k;k++){
        if (dp1[b[0]]<=k){
            dp2[0][k]=c[0];
        }
    }
    for(int i=1;i<n;i++){
        if (b[i]==1){
            dp2[i][0]=dp2[i-1][0]+c[i];
        }
        else dp2[i][0]=dp2[i-1][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=new_k;j++){
            //skip
            dp2[i][j]=dp2[i-1][j];
            if (dp1[b[i]]<=j){
                dp2[i][j]=max(dp2[i][j],c[i]+dp2[i-1][j-dp1[b[i]]]);
            }
        }
    }
    if (k>=new_k){
        print(dp2[n-1][new_k]);
    }
    else{
        print(dp2[n-1][k]);
    }
}  

int main(){
    fastio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
 
