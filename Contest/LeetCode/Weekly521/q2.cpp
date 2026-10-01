class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int> mp;
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            if (nums[i] == nums[i-1]){
                ans++;
            }
            else{
                pair<int,int> temp;
                int x = nums[i-1], y = nums[i];
                if (y < x){
                    swap(x,y);
                }
                mp[{x,y}]++;
            }
        }
        int maxi = 0;
        for(auto &it:mp){
            maxi = max(maxi, it.second);
        }
        return ans + maxi;
    }
};
