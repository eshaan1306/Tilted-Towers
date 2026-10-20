class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divisors;
        for(int k=1;k*k<=n;k++){
            if (n%k == 0){
                divisors.push_back(k);
                if (n/k != k){
                    divisors.push_back(n/k);
                }
            }
        }
        int ans = 0;
        //loop over all possible answers
        for(auto &k:divisors){
            //check if min(i+1) >= max(i)
            int prevMaxi = INT_MIN;
            bool pos = true;
            for(int i=0;i<n;i+=k){
                int curMin = INT_MAX;
                int curMax = INT_MIN;
                for(int j=i;j<i+k;j++){
                    curMin = min(curMin,nums[j]);
                    curMax = max(curMax,nums[j]);
                }
                if (curMin < prevMaxi){
                    pos = false;
                    break;
                }
                prevMaxi = curMax;
            }
            if (!pos){
                continue;
            }
            //now we will check if we can sort each subarray with rotations
            for(int i=0;i<n;i+=k){
                int indx = -1;
                for(int j=i+1;j<i+k;j++){
                    if (nums[j] < nums[j-1]){
                        indx = j;
                        break;
                    }
                }
                //valid
                if (indx == -1){
                    continue;
                }
                for(int j=indx+1;j<i+k;j++){
                    if (nums[j] < nums[j-1]){
                        pos = false;
                        break;
                    }
                }
                if (!pos){
                    break;
                }
                if (nums[i] < nums[i+k-1]){
                    pos = false;
                }
                if (!pos){
                    break;
                }
            }
            if (pos){
                ans += k;
            }
        }
        return ans;
    }
};
