class Solution {
public:

    int nCr(int n,int r){
        if (r<0 || r>n) return 0;
        r=min(r,n-r);
        int ans=1;
        for (int i=1;i<=r;i++){
            long long res=1LL*ans;
            res*=(n-r+i);
            res/=i;
            if (res>1e6){
                return INT_MAX;
            }
            ans*=(n-r+i);
            ans/=i;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        char mid='*';
        for(char ch='a';ch<='z';ch++){
            if (freq[ch-'a']&1){
                mid=ch;
            }
            freq[ch-'a']/=2;
        }
        string ans;
        int n=(s.size())/2;
        for(int i=0;i<n;i++){
            //we want to fix the character here
            bool found=false;
            for(char ch='a';ch<='z';ch++){
                if (freq[ch-'a']==0){
                    continue;
                }
                freq[ch-'a']--;
                int ways=1;
                int len=n-i-1;
                //calculation to calculate the ways
                for(char c='a';c<='z';c++){
                    int comb=nCr(len,freq[c-'a']);
                    if (comb==INT_MAX){
                        ways=INT_MAX;
                        break;
                    }
                    long long res=1LL*ways*comb;
                    if (res>=1LL*k){
                        ways=INT_MAX;
                        break;
                    }
                    ways*=comb;
                    len-=freq[c-'a'];
                }
                if (ways>=k){
                    ans.push_back(ch);
                    found=true;
                    break;
                }
                else{
                    k-=ways;
                    freq[ch-'a']++;
                }
            }
            if (!found){
                return "";
            }
        }
        string rev=ans;
        reverse(rev.begin(),rev.end());
        if (mid!='*'){
            ans.push_back(mid);
        }
        ans=ans+rev;
        return ans;
    }
};
