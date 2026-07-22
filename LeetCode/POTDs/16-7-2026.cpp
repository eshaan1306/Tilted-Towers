class Solution {
public:

    int gcd(int a,int b){
        if (b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd(n);
        prefixGcd[0]=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixGcd[i]=gcd(maxi,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0,j=prefixGcd.size()-1;
        long long ans=0;
        while(i<j){
            ans+=gcd(prefixGcd[i++],prefixGcd[j--]);
        }
        return ans;
    }
};
