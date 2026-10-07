class Solution {
public:

    unordered_set<string> ans;

    void soln(string &s,string &cand,int i,int cnt,int cur){
        if (i == s.size()){
            if (cur == 0 && cnt == 0){
                ans.insert(cand);
            }
            return;
        }
        if (s[i] >= 'a' && s[i] <= 'z'){
            cand.push_back(s[i]);
            soln(s,cand,i+1,cnt,cur);
            cand.pop_back();
        }
        else if (s[i] == '('){
            cand.push_back(s[i]);
            soln(s,cand,i+1,cnt,cur+1);
            cand.pop_back();
            if (cnt > 0){
                soln(s,cand,i+1,cnt-1,cur);
            }
        }
        else{
            if (cur > 0){
                cand.push_back(s[i]);
                soln(s,cand,i+1,cnt,cur-1);
                cand.pop_back();
            }
            if (cnt > 0){
                soln(s,cand,i+1,cnt-1,cur);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int cnt = 0;
        int n = s.size();
        int cur = 0;
        for(int i=0;i<n;i++){
            if (s[i] == '('){
                cur++;
            }
            else if (s[i] == ')'){
                cur--;
                if (cur < 0){
                    cur = 0;
                    cnt++;
                }
            }
        }
        cnt += cur;
        string cand;
        soln(s,cand,0,cnt,0);
        return vector<string>(ans.begin(), ans.end());
    }
};
