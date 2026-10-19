class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int startIndx = 0;
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if (nums[i] == target){
                cnt++;
            }
            else if (nums[i] < target){
                startIndx++;
            }
        }
        vector<int> ans;
        for(int i=0;i<cnt;i++){
            ans.push_back(startIndx + i);
        }
        return ans;
    }
};
