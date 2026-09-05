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
basically start with distributing as much as you can 
once you reach a point where distribution is not possible, 
just add to the set which doesnt have the current largest mex
so that the mex doesnt shoot up
we can the mexes to be same as much as they can 
*/

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mexA=0,mexB=0,mexC=0;
    map<int,int> freq;
    map<int,vector<int>> indices;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
        indices[a[i]].pb(i);
    }
    /*
    if 1, equally distr
    if 2, send one to A, other to B 
    if 3, send to only A
    if not present, send strictly to C
    */
    map<int,int> mp;
    int cur=0;
    for(auto &it:freq){
        int el = it.first;
        int f = it.second;
        //mexes already been decided
        if (el != cur){
            break;
        }
        //best just distribute the elements to the multisets
        if (f>=3){
            mexA++;
            mexB++;
            mexC++;
            cur++;
            mp[el]=1;
        }
        //here just send to the first 2 sets, then the remaining elements will go to 3
        //we will benefit because till now the distr is equal then it wont affect 3rd
        else if (f==2){
            mexA++;
            mexB++;
            mp[el]=2;
            break;
        }
        //exact same logic as above
        else if (f==1){
            mexA++;
            mp[el]=3;
            break;
        }
    }
    bool flag = (mexA + mexB + mexC >= 2*max(mexA,max(mexB,mexC)));
    if (flag){
        yes;
    }
    else{
        no;
        return;
    }
    string s(n,'C');
    for(auto &it:mp){
        int el = it.first;
        int state = it.second;
        if (state==1){
            for(int i=0;i<indices[el].size();i++){
                if (i%3 == 0){
                    s[indices[el][i]]='A';
                }
                else if (i%3 == 1){
                    s[indices[el][i]]='B';
                }
                else{
                    s[indices[el][i]]='C';
                }
            }
        }
        else if (state==2){
            s[indices[el][0]]='A';
            s[indices[el][1]]='B';
        }
        else if (state==3){
            s[indices[el][0]]='A';
        }
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