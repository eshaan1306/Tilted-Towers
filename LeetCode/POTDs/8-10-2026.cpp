class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int n = s.size();
        int i = 0;
        while(i<n){
            int cur = 1;
            i++;
            while(i<n){
                if (s[i] == '('){
                    cur++;
                }
                else{
                    cur--;
                }
                if (cur == 0){
                    i++;
                    break;
                }
                ans.push_back(s[i++]);
            }
        }
        return ans;
    }
};
