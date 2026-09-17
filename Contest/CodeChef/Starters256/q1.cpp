#include <bits/stdc++.h>
using namespace std;

void solve(){
    int A,B;
	cin>>A>>B;
	if ((A-B)&1){
	    cout<<-1;
	    return;
	}
	cout<<((A-B)/2);
}

int main() {
	// your code goes here
	solve();
	return 0;
}
