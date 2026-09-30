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

int helper(vl &a,ll d){
    int low = 0;
    int high = a.size()-1;
    int ans = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(a[mid] <= d){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vl a(k+1),b(k+1);
    a[0] = 0;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    b[0] = 0;
    for(int i=1;i<=k;i++){
        cin>>b[i];
    }
    vl time(k+1,0);
    for(int i=1;i<=k;i++){
        time[i] = b[i] - b[i-1];
    }
    // speed = distance/time
    vpll speed(k);
    for(int i=0;i<k;i++){
        speed[i] = {a[i+1]-a[i],time[i+1]};
    }
    vl ans(q);
    for(int i=0;i<q;i++){
        ll d;
        cin>>d;
        int indx = helper(a,d);
        if(a[indx] == d){
            ans[i] = b[indx];
            continue;
        }
        ll distance = d-a[indx];
        /*distance / speed
        = distance / (speed.first / speed.second)
        = distance * speed.second / speed.first
        */
        ll extra_time = distance*speed[indx].second/speed[indx].first;
        ans[i] = b[indx] + extra_time;
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