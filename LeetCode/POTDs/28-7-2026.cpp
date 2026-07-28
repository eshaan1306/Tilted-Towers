class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0); 
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        string fwd,rev;
        for(char ch='a';ch<='z';ch++){
            if (freq[ch-'a']>1){
                int f=freq[ch-'a']/2;
                for(int i=0;i<f;i++){
                    fwd.push_back(ch);
                    rev.push_back(ch);
                }
                freq[ch-'a']-=2*f;
            }
        }
        for(char ch='a';ch<='z';ch++){
            if (freq[ch-'a']==1){
                fwd.push_back(ch);
                break;
            }
        }
        reverse(rev.begin(),rev.end());
        string ans=fwd+rev;
        return ans;
    }
};
