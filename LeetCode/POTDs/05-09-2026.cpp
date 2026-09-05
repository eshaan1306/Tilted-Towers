class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = -1;
        int n=nums.size();
        vector<int> prefMax(n),sufMin(n);
        prefMax[0]=nums[0];
        sufMin[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefMax[i]=max(prefMax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            sufMin[i]=min(sufMin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int val = prefMax[i]-sufMin[i];
            if (val<=k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
