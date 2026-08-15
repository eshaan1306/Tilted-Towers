class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        int cur = 0;
        for(auto &f:requests){
            ans += abs(cur-f);
            cur=f;
        }
        return ans;
    }
};
