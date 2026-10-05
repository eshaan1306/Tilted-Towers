class Solution {
public:

    int soln(string &s, int &i) {
        int cur = 0;
        while(i < s.size()){
            //getting inside
            if (s[i] == '('){
                i++;
                //best, no bt
                if (s[i] == ')'){
                    cur++;
                    i++;
                    if (i == s.size()){
                        continue;
                    }
                    
                }
                else{
                    //this means this is (A)
                    int A = soln(s,i);
                    cur += 2*A; 
                }
            }
            else{
                //')', so this is the end 
                i++;
                return cur;
            }
        }
        return cur;
    }

    int scoreOfParentheses(string s) {
        int i=0;
        return soln(s, i);
    }
};
