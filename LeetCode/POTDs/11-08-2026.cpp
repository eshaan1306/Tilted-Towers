class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x:nums){
            st.insert(x);
        }
        int longest=nums[0];
        for(int i=1;i<nums.size();i++){
            if (nums[i] == nums[i-1]+1){
                longest += nums[i];
            }
            else{
                break;
            }
        }
        for(int i=longest;i<=1276;i++){
            if (st.find(i) == st.end()){
                return i;
            }
        }
        return -1;
    }
};
