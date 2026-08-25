class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cur=1;
        for(auto &x:nums){
            int target = (cur*k);
            if (x>target){
                return target;
            }
            else if (x==target){
                cur++;
            }
        }
        return cur*k;
    }
};
