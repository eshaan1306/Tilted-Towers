class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans;
        int n = s.size();
        int i = 0;
        while(i < n){
            if (s[i] >= 'a' && s[i] <= 'z'){
                ans.push_back(s[i++]);
            }
            else{
                //its '('
                i++;
                string wrd;
                while(i<n && s[i] != ')'){
                    wrd.push_back(s[i++]);
                }
                if (mp.find(wrd) == mp.end()){
                    ans.push_back('?');
                }
                else{
                    ans += mp[wrd];
                }
                i++;
            }
        }
        return ans;
    }
};
