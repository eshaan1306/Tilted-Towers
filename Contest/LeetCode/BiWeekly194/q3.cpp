class Solution {
public:

    int countMagicalPairs(string s) {
        int n = s.size();
        int ans = 0;
        for(int j=0;j<n-1;j++){
            vector<int> cntLeft(27,0);
            vector<int> cntRight(27,0);
            unordered_set<char> st;
            for(int i=j;i>=0;i--){
                st.insert(s[i]);
                cntLeft[st.size()]++;
            }
            st.clear();
            for(int i=j+1;i<n;i++){
                st.insert(s[i]);
                cntRight[st.size()]++;
            }
            for(int val=0;val<=26;val++){
                ans += cntLeft[val]*cntRight[val];
            }
        }
        return ans;
    }
};
