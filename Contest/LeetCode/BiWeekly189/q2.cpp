class Solution {
public:

    void leftRotate(string &s){
        char ch=s[0];
        int n=s.size();
        for(int i=1;i<n;i++){
            s[i-1] = s[i];
        }
        s[n-1]=ch;
    }
    
    int minOperations(string s) {
        int mini=INT_MAX;
        int n=s.size();
        for(int iter=0;iter<=n-1;iter++){
            int i=0,j=n-1;
            int cur = iter;
            while(i<j){
                int ix1 = s[i] - 'a';
                int ix2 = s[j] - 'a';
                int del = abs(ix1-ix2);
                int ops = min(del,26-del);
                cur+=ops;
                i++,j--;
            }
            mini=min(mini,cur);
            leftRotate(s);
        }
        return mini;
    }
};
