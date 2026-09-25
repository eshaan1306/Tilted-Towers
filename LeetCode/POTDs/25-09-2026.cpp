class Solution {
public:

    set<string> soln(int &i, string &expression){
        set<string> st;
        set<string> cur = {""};
        while(i < expression.size() && expression[i] != '}'){
            //union
            if(expression[i] == ','){
                for(auto &s:cur){
                    st.insert(s);
                }
                cur = {""};
                i++;
            }
            //bracket expression
            else if(expression[i] == '{'){
                i++; //skip {
                set<string> nxt = soln(i,expression);
                i++; //skip }
                set<string> temp;
                //concatenate
                for(auto &s:cur){
                    for(auto &t:nxt){
                        temp.insert(s+t);
                    }
                }
                cur = temp;
            }
            //letters
            else{
                string wrd;
                while(i < expression.size() && expression[i] >= 'a' && expression[i] <= 'z'){
                    wrd.push_back(expression[i]);
                    i++;
                }
                set<string> temp;
                for(auto &s:cur){
                    temp.insert(s+wrd);
                }
                cur = temp;
            }
        }
        //left
        for(auto &s:cur){
            st.insert(s);
        }
        return st;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> st = soln(i,expression);
        vector<string> ans;
        for(auto &s:st){
            ans.push_back(s);
        }
        return ans;
    }
};
