class Solution {
public:

    set<int> factorize(int n,vector<int> &sieve){
        set<int> res;
        while(n>1){
            res.insert(sieve[n]);
            n/=sieve[n];
        }
        return res;
    }

    int longestSubarray(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for(auto &x:nums){
            maxi=max(x,maxi);
        }
        vector<int> sieve(maxi+1,1);
        for(int i=2;i<=maxi;i++){
            sieve[i]=i;
        }
        for(int i=2;i<=maxi;i++){
            if (sieve[i] != i){
                continue;
            }
            for(int j=i;j<=maxi;j+=i){
                sieve[j]=i;
            }
        }
        map<int,int> cnt;
        int l=0,r=0,ans=0;
        int n=nums.size();
        while(r<n){
            set<int> f=factorize(nums[r],sieve);
            for(auto &x:f){
                cnt[x]++;
            }
            while(cnt.size()>k){
                set<int> nf=factorize(nums[l],sieve);
                for(auto &x:nf){
                    cnt[x]--;
                    if (cnt[x]==0){
                        cnt.erase(x);
                    }
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
