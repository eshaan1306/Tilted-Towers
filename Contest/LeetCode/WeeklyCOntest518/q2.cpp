class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1,0);
        long long tol=0;
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]+nums[i];
            tol += nums[i];
        }
        //number of rotations
        /*
        so basically first we would have first n/2
        then 1...n/2+1
        then 2...n/2 + 2
        at lets say some n/2 + k time we would have 
        n/2 + k + n + k 
        which is some extra elements after k 
        */
        int ans = 0;
        for(int i=0;i<n;i++){
            int req = n/2 + i;
            long long firstHalf;
            if (req <= n){
                firstHalf = pref[req] - pref[i];
            }
            else{
                int extra = req - n;
                firstHalf = pref[n] - pref[i] + pref[extra];
            }
            long long secondHalf = tol - firstHalf;
            if (firstHalf > secondHalf){
                ans++;
            }
        }
        return ans;
    }
};©leetcode
