class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> dp(n+1,0);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1];
            if (j!=-1 && word1[i] == word2[j]){
                dp[i]++;
                j--;
            }
        }
        //smallest lexo would be the first valid
        vector<int> ans;
        j=0;
        int indx = -1;
        for(int i=0;i<n;i++){
            if (j==m){
                break;
            }
            if (word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                //lets say we match
                int req = (m-j-1);
                if (dp[i+1]>=req){
                    ans.push_back(i);
                    indx=i;
                    j++;
                    break;
                }
            }
        }
        if (j==m){
            return ans;
        }
        if (indx==-1){
            return {};
        }
        for(int i=indx+1;i<n;i++){
            if (j==m){
                break;
            }
            if (word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
        }
        return ans;
    }
};
