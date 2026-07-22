class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            last[ch-'a']=i;
        }
        string ans;
        vector<int> vis(26,0);
        for(int i=0;i<n;i++){
            char ch=s[i];
            if (vis[ch-'a']){
                continue;
            }
            while(ans.size() && ans.back()>ch && last[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(ch);
            vis[ch-'a']=1;
        }
        return ans;
    }
};
