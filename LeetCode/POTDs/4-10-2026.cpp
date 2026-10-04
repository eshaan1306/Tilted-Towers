class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> stk;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                q.push(i);
            }
            else if(s[i] == '(') {
                stk.push(i);
            }
            else {
                if(!stk.empty()) {
                    stk.pop();
                }
                else if(!q.empty()) {
                    q.pop();
                }
                else {
                    return false;
                }
            }
        }
        if(q.size() < stk.size()) {
            return false;
        }
        stack<int> stkStar;
        while(!q.empty()) {
            stkStar.push(q.front());
            q.pop();
        }
        while(!stk.empty()) {
            if(stkStar.top() < stk.top()) {
                return false;
            }
            stk.pop();
            stkStar.pop();
        }
        return true;
    }
};
