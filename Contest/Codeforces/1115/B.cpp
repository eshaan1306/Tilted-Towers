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

*/

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (n==1){
        print(0);
        return;
    }
    int cnt1=0,cnt0=0;
    int extra1=0,extra0=0;
    if (s[0]=='1'){
        extra1++;
    }
    else{
        extra0++;
    }
    if (s[n-1]=='1'){
        extra1++;
    }
    else{
        extra0++;
    }
    int i=0;
    while(i<n){
        int cnt=1;
        int j=i+1;
        while(j<n && s[j]==s[i]){
            j++;
            cnt++;
        }
        if (s[i]=='0'){
            cnt0 += (cnt-1);
        }
        else{
            cnt1 += (cnt-1);
        }
        i=j;
    }
    if (abs(cnt1-cnt0)<=1){
        print(cnt1+cnt0);
        return;
    }
    if (cnt1>cnt0){
        while(extra0){
            cnt0++;
            extra0--;
            if (abs(cnt1-cnt0)<=1){
                print(cnt1+cnt0);
                return;
            }
        }
    }
    else{
        while(extra1){
            cnt1++;
            extra1--;
            if (abs(cnt1-cnt0)<=1){
                print(cnt1+cnt0);
                return;
            }
        }
    }
    print(-1);
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