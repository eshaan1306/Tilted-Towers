class Solution {
public:

/*
bs wont work because its not monotonic 
observation 1 : the substring should end with )
so whenever we get ), we can check whether thats valid or not
now lets say if we are at j where s[j] == )
and we were to say s[i...j] is valid, if at some k (k>j)
we have to check only for [0..i-1] ... [j+1..k]
(())
()()
*/

    int longestValidParentheses(string s) {
        int ans = 0;
        //push the index of '('
        stack<int> stk;
        int n = s.size();
        //length of longest ending here at i
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            if (s[i] == '('){
                stk.push(i);
            }
            else{
                //no valid config possible
                if (stk.empty()){
                    continue;
                }
                int indx = stk.top();
                stk.pop();
                if (s[i-1] == ')'){
                    //definitely i know, this would have formed a valid sequence
                    //because if it did not, that means no '(', but there is !!
                    dp[i] = dp[i-1] + 2;
                    int prior = 0;
                    if (indx - 1 >= 0){
                        prior = dp[indx-1];
                    }
                    dp[i] += prior;
                }
                else{
                    int prior = 0;
                    if (i-2 >= 0){
                        prior = dp[i-2];
                    }
                    dp[i] = prior + 2;
                }
            }
        }
        for(auto &x:dp){
            ans = max(ans,x);
        }
        return ans;
    }
};
