class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cur = 0;
        for(auto &ch:s){
            if (ch == '('){
                cur++;
                ans = max(ans,cur);
            }
            else if (ch == ')'){
                cur--;
            }
        }
        return ans;
    }
};
