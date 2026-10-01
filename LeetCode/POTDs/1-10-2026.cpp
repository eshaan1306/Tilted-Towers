class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto &c:s){
            if (c=='(' || c=='[' || c=='{'){
                stk.push(c);
            }
            else{
                if (stk.empty()){
                    return false;
                }
                char cur=stk.top();
                if (cur=='(' && c==')'){
                    stk.pop();
                }
                else if (cur=='{' && c=='}'){
                    stk.pop();
                }
                else if (cur=='[' && c==']'){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
