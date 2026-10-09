
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int cur = 0;
        int i = 0;
        while(i<n){
            if (s[i] == '('){
                cur++;
            }
            else{
                if (i + 1 < n && s[i + 1] == ')'){
                    i++;
                }
                else{
                    ans++; 
                }
                if (cur > 0){
                    cur--;
                }
                else{
                    ans++; 
                }
            }
            i++;
        }
        ans += 2*cur;
        return ans;
    }
};
