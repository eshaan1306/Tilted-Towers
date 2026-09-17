#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    cout<<(2*max(0,k-n));
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
