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
i was thinking of bs on answer
condtion on if >=x is possible 
lets say it is possible the mex to be x
for number of subarrays being k+1
if i think [  ] [  ] [   ] [   ]
each of their mex is x 
i can just merge any 2, the minimum mex would still be
x, so condition on number of subarrays can be relaxed to >=k
*/

bool check(vi &a,int n,int k,int mid){
    int i=0;
    int cnt=0;
    while(i<n){
        int left=mid;
        int j=i;
        vector<int> present(mid,0);
        while(left && j<n){
            //already there or useless
            if (a[j]>=mid || present[a[j]]){
                j++;
                continue;
            }
            else{
                present[a[j]]=1;
                left--;
                j++;
            }
        }
        if (left){
            if (cnt>=k){
                return true;
            }
            else{
                return false;  
            }
        }
        i=j;
        cnt++;
    }
    return cnt>=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int low=1,high=n;
    int ans=0;
    while(low<=high){
        int mid = low + (high-low)/2;
        //check calling
        bool pos = check(a,n,k,mid);
        if (pos){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
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