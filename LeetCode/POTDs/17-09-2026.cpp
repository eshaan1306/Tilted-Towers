class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        map<int,int> mp1,mp2;
        mp1[0] = -1;
        int cur = 0;
        vector<int> dp1(n,INT_MAX);
        for(int i=0;i<n;i++){
            cur += arr[i];
            int req = cur-target;
            int len = INT_MAX;
            if (mp1.find(req) != mp1.end()){
                len = i-mp1[req];
            }
            if (i==0){
                dp1[i] = len;
            }
            else{
                dp1[i] = min(dp1[i-1],len);
            }
            mp1[cur] = i;
        }
        cur = 0;
        mp2[0] = n;
        vector<int> dp2(n,INT_MAX);
        for(int i=n-1;i>=0;i--){
            cur += arr[i];
            int req = cur-target;
            int len = INT_MAX;
            if (mp2.find(req) != mp2.end()){
                len = mp2[req]-i;
            }
            if (i==n-1){
                dp2[i] = len;
            }
            else{
                dp2[i] = min(dp2[i+1],len);
            }
            mp2[cur] = i;
        }
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++){
            if (dp1[i] != INT_MAX && dp2[i+1] != INT_MAX){
                ans = min(ans,dp1[i] + dp2[i+1]);
            }
        }
        if (ans == INT_MAX){
            ans = -1;
        }
        return ans;
    }
};
