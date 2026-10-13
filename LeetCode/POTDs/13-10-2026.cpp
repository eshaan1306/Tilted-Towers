class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        int indx = (n+1)/2;
        for(int i=0;i<indx;i++){
            ans += 1LL*nums[i]*nums[i];
        }
        for(int i=indx;i<n;i++){
            ans -= 1LL*nums[i]*nums[i];
        }
        return ans;
    }
};
