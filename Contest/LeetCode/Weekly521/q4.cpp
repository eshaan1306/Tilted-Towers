class Solution {
public:

    vector<vector<long long>> dp;

    // true means we have a previous meeting to it
    long long soln(int i, vector<vector<int>>& meetings, bool flag) {
        int n = meetings.size();
        if(i >= n)
            return 0LL;
        if(dp[i][flag] != -1)
            return dp[i][flag];
        // select this meeting
        long long rev1 = meetings[i][2];
        if(flag){
            rev1 += meetings[i][0];
        }
        int end = meetings[i][1];
        int l = i + 1, r = n - 1;
        int indx = n;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(meetings[mid][0] >= end) {
                indx = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        long long op1 = soln(indx, meetings, true);
        if(op1 != 0){
            op1 -= meetings[i][1];
        }
        rev1 += op1;
        // don't select
        long long rev2 = soln(i + 1, meetings, flag);
        return dp[i][flag] = max(rev1, rev2);
    }

    long long maxEarnings(vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        dp.assign(meetings.size(), vector<long long>(2, -1));
        return soln(0, meetings, false);
    }
};
