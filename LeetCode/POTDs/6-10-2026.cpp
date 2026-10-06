class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if (s[i] == '('){
                cnt++;
            }
            else{
                cnt--;
            }
            if (cnt < 0){
                ans++;
                cnt = 0;
            }
        }
        ans += cnt;
        return ans;
    }
};
