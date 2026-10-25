class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int l = 0, r = 0;
        while(r<n){
            if (nums[r] >= minK && nums[r] <= maxK){
                r++;
            }
            else{
                //n(n+1)/2
                long long len = r-l;
                ans += ((len)*(len+1))/2;
                r++;
                l = r;
            }
        }
        long long len = r-l;
        ans += ((len)*(len+1))/2;
        return ans;
    }
};
