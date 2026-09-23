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
we can view it as an operation
where we are incrementing one of the digits
d > 1
and decrementing 1st digit always 
so i think we should focus at 1 digit at a time
and then pick the minimum for each digit
*/

void solve(){
    ll n;
    cin>>n;
    vi dig;
    while(n){
        dig.pb(n%10);
        n/=10;
    }
    for(auto &x:dig){
        if (x == 7){
            print(0);
            return;
        }
    }
    int ans = INT_MAX;
    for(int i=1;i<=dig.size();i++){
        int cnt = 0;
        vi temp = dig;
        if(i == temp.size()){
            temp.pb(0);
        }
        while(true){
            temp[i]++;
            cnt++;
            temp[0]--;
            if(temp[0] == -1){
                temp[0] = 9;
                for(int j=1;j<=i;j++){
                    if(temp[j] == 0){
                        temp[j] = 9;
                    }
                    else{
                        temp[j]--;
                        break;
                    }
                }
            }
            if(temp[i] == 10){
                temp[i] = 0;
                bool flag = false;
                for(int j=i+1;j<temp.size();j++){
                    temp[j]++;
                    if(temp[j] == 10){
                        temp[j] = 0;
                    }
                    else{
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    temp.pb(1);
                }
            }
            bool flag = false;
            for(auto &x:temp){
                if(x == 7){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        ans = min(ans,cnt);
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