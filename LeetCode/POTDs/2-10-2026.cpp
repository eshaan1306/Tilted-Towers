class Solution {
public:

    void helper(string &curr, int n, int open, int close, vector<string> &ans ){
        if (open==n && close==n){
            ans.push_back(curr);
            return;
        }
        if (open<n){
            curr.push_back('(');
            helper(curr,n,open+1,close,ans);
            curr.pop_back();
        }
        if (close<open){
            curr.push_back(')');
            helper(curr,n,open,close+1,ans);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr="";
        helper(curr,n,0,0,ans);
        return ans;
    }
};
