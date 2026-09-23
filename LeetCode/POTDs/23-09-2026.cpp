class Solution {
public:

    int bs1(vector<int> &pref,int target){
        int res = pref.size();
        int low=0,high=res-1;
        while(low <= high){
            int mid = (low+high)/2;
            if (pref[mid] == target){
                res = mid;
                high = mid-1;
            }
            else if (pref[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }

    int bs2(vector<int> &suff,int target){
        int res = suff.size();
        int low=0,high=res-1;
        while(low <= high){
            int mid = (low+high)/2;
            if (suff[mid] == target){
                res = mid;
                low = mid+1;
            }
            else if (suff[mid] > target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pref(n+1,0);
        vector<int> suff(n+1,0);
        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suff[i] = suff[i+1]+nums[i];
        }
        for(int i=0;i<=n;i++){
            int cur = pref[i];
            int rem = x-cur;
            int cnt = bs2(suff,rem);
            if (cnt == n+1 || cnt<i){
                continue;
            }
            ans = min(ans,i+n-cnt);
        }
        if (ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
