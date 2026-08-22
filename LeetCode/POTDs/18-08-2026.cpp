class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto &x:nums){
            freq[x]++;
        }
        if (k==1){
            int maxi=-1;
            for(auto &x:nums){
                if (freq[x] == 1){
                    maxi = max(maxi,x);
                }
            }
            return maxi;
        }
        /*
        now k>=2, that means any index except the first and the last
        would be a part of atleast 2 subarrays
        so elements between 0 and n-1 can never be the answer
        we only have to check for the first and last
        one edge case where k == n
        */
        if (k == nums.size()){
            int maxi = INT_MIN;
            for(auto &x:nums){
                maxi = max(maxi,x);
            }
            return maxi;
        }
        int first = nums[0];
        int last = nums.back();
        if (freq[first]>1 && freq[last]>1){
            return -1;
        }
        else if (freq[first]>1){
            return last;
        }
        else if (freq[last]>1){
            return first;
        }
        return max(first,last);
    }
};
