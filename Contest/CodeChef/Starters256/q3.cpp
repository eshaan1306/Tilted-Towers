#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    if ((n-k)==1){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}
