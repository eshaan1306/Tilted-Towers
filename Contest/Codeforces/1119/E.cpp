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
first observation 
if we have some value x at b[i] 
then every index in the interval (b[i]-d to b[i]+d) should be 0
if we have any possibility of having 1 there, it is not possible 
so this is the only check we have to do 
since we have intervals, can be done easily by a difference array 
*/

void solve(){
    int n;
    cin>>n;
    vi b(n);
    for(int i=0;i<n;i++){   
        cin>>b[i];
    }
    vi diff(n+1,0);
    for(int i=0;i<n;i++){
        if (b[i] == 0 || b[i] == -1){
            continue;
        }
        int l = max(0,i-b[i]+1);
        int r = min(n-1,i+b[i]-1);
        diff[l]++;  
        diff[r+1]--;
    }
    int cur=0;
    vi allowed(n,1);
    for(int i=0;i<n;i++){
        cur += diff[i];
        if (cur > 0){
            allowed[i] = 0;
        }
    }
    //now we have the indees where it is allowed and where it is not allowed
    //initial check
    for(int i=0;i<n;i++){
        if (b[i] == -1){
            continue;
        }
        bool flag = false;
        if (i-b[i] >= 0 && allowed[i-b[i]]){
            flag = true;
        }
        if (i+b[i] < n && allowed[i+b[i]]){
            flag = true;
        }
        if (!flag){
            print(-1);
            return;
        }
    }
    //now if we have passed, it is possible
    //best way for -1 is to check if its possible then 1 else 0
    string s(n,'0');
    for(int i=0;i<n;i++){
        if (allowed[i]){
            s[i] = '1';
        }
        else{
            s[i] = '0';
        }
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        if (s[i] == '1'){
            flag=true;
            break;
        }
    }
    if (!flag){
        print(-1);
        return;
    }
    print(s);
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