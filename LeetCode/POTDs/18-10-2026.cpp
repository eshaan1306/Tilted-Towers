class Solution {
public:
    long long const MOD = 1e9 + 7;
    vector<vector<long long>> ncr;

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            }
            else {
                right.push_back(nums[i]);
            }
        }
        int l = left.size();
        int r = right.size();
        long long a = solve(left);
        long long b = solve(right);
        return (((a * b) % MOD) * ncr[l+r][l]) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        ncr.resize(n+1, vector<long long>(n+1, 0));
        for (int i=0;i<=n;i++){
            ncr[i][0] = 1;
            ncr[i][i] = 1;
            for (int j=1;j<i;j++){
                ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
            }
        }
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
