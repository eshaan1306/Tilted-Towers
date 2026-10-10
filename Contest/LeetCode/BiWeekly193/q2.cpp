class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            int sum = nums[i];
            set<int> st;
            st.insert(nums[i]%k);
            for(int j=i+1;j<n;j++){
                sum += nums[i];
                int req = sum%k;
                st.insert(nums[j]%k);
                //not possible
                if (st.size() > 1){
                    break;
                }
                int val = *(st.begin());
                if (val == req){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
