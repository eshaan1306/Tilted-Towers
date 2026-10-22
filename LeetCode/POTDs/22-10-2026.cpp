class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                pos = i;
                break;
            }
        }
        bool inc = true, dec = true;
        for(int i=0;i<n;i++){
            if(nums[(pos+i)%n] != i){
                inc = false;
            }
            if(nums[(pos+i)%n] != (n-i)%n){
                dec = false;
            }
        }
        int ans = INT_MAX;
        if(inc){
            ans = min(ans,pos);
            ans = min(ans,n-pos+2);
        }

        if(dec){
            ans = min(ans,1+n-1-pos);
            ans = min(ans,1+(pos+1)%n);
        }
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
    
};
