class Solution {
public:

    static int helper(int n){
        int res = 0;
        while(n > 0){
            res += n%10;
            n/=10;
        }
        return res;
    }

    static bool comp(int &a,int &b){
        if (helper(a) == helper(b)){
            return a < b;
        }
        return helper(a) < helper(b);
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        sort(nums.begin(),nums.end(),comp);
        vector<int> convert(n,-1);
        for (int i=0;i<n;i++){
            int old = mp[nums[i]];
            convert[old] = i;
        }
        vector<int> vis(n,0);
        for (int i=0;i<n;i++){
            if (vis[i]){
                continue;
            }
            int j = i;
            int len = 0;
            while (!vis[j]) {
                vis[j] = 1;
                j = convert[j];
                len++;
            }
            ans += len - 1;
        }
        return ans;
    }
};
