class Solution {
public:

    /*
    it is basically asking us to count the number of 
    subarrays with a given product
    let fn(x) == x mod k
    fn(fn(a)*fn(b)) == fn(a*b)
    */

    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);
        for(int i=0;i<nums.size();i++){
            int val = nums[i]%k;
            vector<long long> newdp(k,0);
            //start a new subarray from i
            newdp[val]++;
            //extend all subarrays ending at i-1
            for(int r=0;r<k;r++){
                int nr = (1LL*r*val)%k;
                newdp[nr] += dp[r];
            }
            //all these are valid subarrays
            for(int r=0;r<k;r++){
                ans[r] += newdp[r];
            }
            dp = newdp;
        }
        return ans;
    }
};
