class Solution {
public:

    string ans;

    string soln(int &i,string &s){
        int n = s.size();
        if (i >= n){
            return "";
        }
        string cur;
        //now start is the start of the string which we have to reverse
        while(i<n){
            if (s[i]>='a' && s[i]<='z'){
                cur.push_back(s[i++]);
            }
            else if (s[i] == '('){
                //lets hope this returns the next part reversed
                string nxt = soln(++i,s);
                cur += nxt;
            }
            //this is def a ')'
            else{
                reverse(cur.begin(),cur.end());
                i++;
                return cur;
            }
        }
        return cur;
    }

    string reverseParentheses(string s) {
        int i=0;
        ans = soln(i,s);
        return ans;
    }
};
