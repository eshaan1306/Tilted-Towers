#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.rbegin(),a.rend());
    long long ans=0;
    long long sr=0,sb=sum,cr=0,cb=n;
    for(int i=0;i<n;i++){
        sr+=a[i];
        sb-=a[i];
        cr++,cb--;
        ans=max(ans,sr*cb + sb*cr);
    }
    cout<<ans;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}
