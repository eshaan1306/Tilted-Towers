class Solution {
public:

    bool comp(string &s,int i,int j,int p,int q){
        for(int k=i;k<=j;k++){
            if (s[k] < s[p+(k-i)]){
                return true;
            }
            else if (s[k] > s[p+(k-i)]){
                return false;
            }
        }
        return false;
    }

    int helper(string &s,int k){
        int n=s.size();
        int ans=n+1;
        int l=0,r=0;
        int curCnt=0;
        while(r<n){
            curCnt += (s[r]=='1');
            while(curCnt>k){
                curCnt -= (s[l]=='1');
                l++;
            }
            while(curCnt == k){
                if (s[l] == '1'){
                    break;
                }
                l++;
            }
            if (curCnt==k){
                ans=min(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }

    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        int len = helper(s,k);
        int n = s.size();
        if (len == n+1){
            return ans;
        }
        int cnt=0;
        int start=-1,end=-1;
        for(int i=0;i<len;i++){
            cnt += (s[i] == '1');
        }
        if (cnt == k){
            start=0,end=len-1;
        }
        for(int i=len;i<n;i++){
            cnt -= s[i-len]=='1';
            cnt += s[i]=='1';
            if (cnt == k){
                if (start == -1 && end == -1){
                    start = i-len+1;
                    end = i;
                }
                bool flag = comp(s,start,end,i-len+1,i);
                if (!flag){
                    start = i-len+1;
                    end = i;
                }
            }
        }
        if (start == -1 && end == -1){
            return ans;
        }
        for(int i=start;i<=end;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};
