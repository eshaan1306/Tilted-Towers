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

*/

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxi = INT_MIN;
    for(int i=1;i<n;i++){
        maxi = max(maxi,abs(a[i]-a[i-1]));
    }
    int ans = maxi;
    int cnt = 0;
    for(int i=1;i<n;i++){
        if (abs(a[i]-a[i-1]) == maxi){
            cnt++;
        }
    }
    if (cnt > 2){
        print(ans);
        return;
    }
    if (cnt == 2){
        int l = -1, r = -1;
        /*
        we basically want the walls
        this is the only segment we can play with
        just try if anything can happen and jai mata di 
        */
        for(int i=1;i<n;i++){
            if (abs(a[i]-a[i-1]) == maxi){
                if (l == -1){
                    l = i;
                }
                else{
                    r = i - 1;
                    break;
                }
            }
        }
        for(int i=l;i<=r;i++){
            a[i]*=2;
        }
        reverse(a.begin()+l,a.begin()+r+1);
        int newMaxi = INT_MIN;
        for(int i=1;i<n;i++){
            newMaxi = max(newMaxi,abs(a[i]-a[i-1]));
        }
        ans = min(ans,newMaxi);
        print(ans);
        return;
    }
    /*
    now we have to check sort of in a brute force way 
    lets say ai | ai+1
    this is the wall
    we will either work on 
    [al,ai] or [ai+1,ar] where l >=0 and r < n
    we can use prefix and suffix max to get the optima 
    */
    vi prefixMax(n,INT_MIN),suffixMax(n,INT_MIN);
    for(int i=1;i<n;i++){
        prefixMax[i] = max(prefixMax[i-1],abs(a[i]-a[i-1]));
    }
    for(int i=n-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1],abs(a[i]-a[i+1]));
    }
    int indx = -1;
    for(int i=1;i<n;i++){
        if (abs(a[i]-a[i-1]) == maxi){
            indx = i;
            break;
        }
    }
    int p = indx - 1; 
    //case 1: max edge is left boundary. Segment [p+1, r].
    int internalMaxA = 0;
    for (int r=p+1;r<n;r++){
        int cur = 0;
        if (p > 0){
            cur = max(cur, prefixMax[p]);
        }
        cur = max(cur, 2*internalMaxA);
        cur = max(cur, abs(a[p] - 2*a[r]));
        if (r < n-1){
            cur = max(cur, abs(2*a[p+1] - a[r+1]));
            cur = max(cur, suffixMax[r+1]);
        }
        ans = min(ans, cur);
        if (r < n-1){
            internalMaxA = max(internalMaxA, abs(a[r] - a[r+1]));
        }
    }
    //case 2: max edge is right boundary. Segment [l, p].
    int internalMaxB = 0;
    for (int l=p;l>=0;l--){
        int cur = 0;
        if (l > 0){
            cur = max(cur, prefixMax[l-1]);
        }
        cur = max(cur, 2*internalMaxB);
        if (l > 0){
            cur = max(cur, abs(a[l-1] - 2*a[p]));
        }
        cur = max(cur, abs(2*a[l] - a[p+1]));
        cur = max(cur, suffixMax[p+1]);
        ans = min(ans, cur);
        if (l > 0){
            internalMaxB = max(internalMaxB, abs(a[l-1] - a[l]));
        }
    }
    print(ans);
    return;
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