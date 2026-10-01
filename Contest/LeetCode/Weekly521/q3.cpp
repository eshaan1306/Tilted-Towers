class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        map<int,int> mp;
        while(r < n){
            int x = nums[r];
            while(true){
                bool bad = false;
                // check 1
                for(int a = 1; a <= x / 2; a++){
                    int b = x - a;
                    if(a == b){
                        if(mp[a] >= 2){
                            bad = true;
                            break;
                        }
                    }
                    else{
                        if(mp[a] && mp[b]){
                            bad = true;
                            break;
                        }
                    }
                }
                // check 2
                if(!bad){
                    for(int a = x + 1; a <= 500; a++){
                        int b = a - x;
                        if(mp[a] && mp[b]){
                            bad = true;
                            break;
                        }
                    }
                }
                if(!bad) break;
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            mp[nums[r]]++;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
