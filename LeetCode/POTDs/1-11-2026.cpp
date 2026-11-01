class Solution {
public:

    /*
    1 2 3 4 ( 3 + 2 + 1)
    2 3 4 4
    3 4 4 5
    4 5 4 6
    5 5 5 7
    6 6 6
    7 7 7
    */

    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans  = 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            ans += nums[i] - nums[0];
        }
        return ans;
    }
};
