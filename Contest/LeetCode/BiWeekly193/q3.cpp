class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            nums[i]%=k;
        }
        int i=0;
        while(i < n){
            int j = i+1;
            while(j<n && nums[j] == nums[i]){
                j++;
            }
            int len = j-i;
            /*
            so the sum is len*rem
            each number is rem 
            (max len actually from 1 to len)
            we want len*rem-rem == k
            rem*(len - 1) % k == 0
            we know rem is less than k 
            so there MUST exist some min value
            we multiply with rem, to make it
            divisinle by k
            lets say for rem == 4 , k is 5
            we need lowest is 20
            so rem * x == 20 , x = 5
            lcm(rem,k)/rem
            */
            long long rem = nums[i];
            long long lcm = (rem*k)/gcd(k,rem);
            if (rem == 0){
                ans = max(ans,len);
                i = j;
                continue;
            }
            long long x = lcm/rem;
            int maxi = 1 + ((len-1)/x)*x;
            ans = max(ans,maxi);
            i = j;
        }
        return ans;
    }
};
