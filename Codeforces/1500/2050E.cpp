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
a == b == 10^3
O(a*b)
*/

//recursion 

int soln(int i,int j,string &a,string &b,string &c){
    if (i==a.size() && j==b.size()){
        return 0;
    }
    if (i==a.size()){
        return (b[j] != c[a.size() + j]) + soln(i,j+1,a,b,c);
    }
    if (j==b.size()){
        return (a[i] != c[b.size() + i]) + soln(i+1,j,a,b,c);
    }
    int opt1 = (b[j] != c[i + j]) + soln(i,j+1,a,b,c);
    int opt2 = (a[i] != c[j + i]) + soln(i+1,j,a,b,c);
    return min(opt1,opt2);
}

void solve(){
    string a,b,c;  
    cin>>a>>b>>c;
    int n=a.size();
    int m=b.size();
    vvi dp(n+1,
        vi (m+1,0)
    );
    /*
    dp[i][j] == min number of changes
    to build till i and j th index of 
    a and b respectively
    */
    //base cases
    for(int i=n-1;i>=0;i--){
        dp[i][m] = (a[i] != c[m+i]) + dp[i+1][m];
    }
    for(int i=m-1;i>=0;i--){
        dp[n][i] = (b[i] != c[n+i]) + dp[n][i+1];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            /*
            we have 2 options
            we will either match it with a 
            or we will match it with b
            and we will take minimum of both
            */
            //index currently of c
            int indx = i+j;
            int op1 = (a[i] != c[indx]) + dp[i+1][j];
            int op2 = (b[j] != c[indx]) + dp[i][j+1];
            dp[i][j] = min(op1,op2);
        }
    }
    print(dp[0][0]);
    // int ans = soln(0,0,a,b,c);
    // cout<<dp[0][0]<<" "<<ans;
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