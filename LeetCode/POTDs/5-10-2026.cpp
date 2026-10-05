class Solution {
public:

    int soln(string &s, int l, int r) {
        // (), base case
        if (l + 1 == r) return 1;   
        int cur = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '(') cur++;
            else cur--;
            if (cur == 0) {
                if (i == r) {
                    // whole thing is (A)
                    return 2 * soln(s, l + 1, r - 1);
                }
                // whole thing is AB
                return soln(s, l, i) + soln(s, i + 1, r);
            }
        }
        return 0;
    }

    int scoreOfParentheses(string s) {
        return soln(s, 0, s.size() - 1);
    }
};
