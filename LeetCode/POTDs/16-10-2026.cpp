
class Solution {
    using ll = long long;
    static constexpr ll MOD = 1e9 + 7;

    struct Fenwick {
        int n;
        vector<ll> bit1, bit2;

        Fenwick(int n) : n(n), bit1(n + 1), bit2(n + 1) {}

        void add(vector<ll>& bit, int i, ll val) {
            for (; i <= n; i += i & -i)
                bit[i] += val;
        }

        ll query(const vector<ll>& bit, int i) {
            ll sum = 0;
            for (; i > 0; i -= i & -i)
                sum += bit[i];
            return sum;
        }

        // 1-indexed range addition
        void rangeAdd(int l, int r, ll val) {
            add(bit1, l, val);
            add(bit1, r + 1, -val);

            add(bit2, l, val * (l - 1));
            add(bit2, r + 1, -val * r);
        }

        ll prefixSum(int i) {
            return query(bit1, i) * i - query(bit2, i);
        }

        ll rangeSum(int l, int r) {
            return prefixSum(r) - prefixSum(l - 1);
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        Fenwick fw(n);
        vector<int> last(100001, -1);

        ll curr = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            // Convert starting indices to 1-indexed
            int L = p + 2;
            int R = i + 1;

            // Sum of old distinct counts in [L,R]
            ll oldSum = fw.rangeSum(L, R);

            // (d+1)^2 - d^2 = 2d+1
            curr += 2 * oldSum + (R - L + 1);

            // Increase distinct counts by 1
            fw.rangeAdd(L, R, 1);

            ans = (ans + curr) % MOD;

            last[nums[i]] = i;
        }

        return (int)ans;
    }
};
