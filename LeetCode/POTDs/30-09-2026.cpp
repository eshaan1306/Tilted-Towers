class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);
        int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++){
            if (seq[i] == '('){
                if (cnt0 == 0){
                    cnt0++;
                    ans[i] = 0;
                }
                else if (cnt1 == 0){
                    cnt1++;
                    ans[i] = 1;
                }
                else if (cnt1 < cnt0){
                    cnt1++;
                    ans[i] = 1;
                }
                else{
                    cnt0++;
                    ans[i] = 0;
                }
            }
            else{
                if (cnt1 > cnt0){
                    cnt1--;
                    ans[i] = 1;
                }
                else{
                    cnt0--;
                    ans[i] = 0;
                }
            }
        }
        return ans;
    }
};
