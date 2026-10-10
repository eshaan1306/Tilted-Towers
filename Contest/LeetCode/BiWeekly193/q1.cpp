class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int prod = INT_MIN;
        vector<int> ans(2);
        ans[0] = ans[1] = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (i==j){
                    continue;
                }
                if (nums[i] + nums[j] == target){
                    if (nums[i] > nums[j]){
                        if (prod < nums[i]*nums[j]){
                            prod = nums[i]*nums[j];
                            ans[0] = i;
                            ans[1] = j;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
