class Solution {
public:

    void leftRotate(string &s){
        char ch = s[0];
        int n = s.size();
        for(int i=0;i<n-1;i++){
            s[i] = s[i+1];
        }
        s[n-1] = ch;
    }
    
    int countRotations(string s, int k) {
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n-1;j++){
                if (s[j] == s[j+1]){
                    cnt++;
                }
            }
            if (cnt==k){
                ans++;
            }
            leftRotate(s);
        }

        return ans;
    }
};©leetcode
