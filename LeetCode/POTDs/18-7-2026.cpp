class Solution {
public:

    int gcd(int a,int b){
        if (b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto &x:nums){
            maxi=max(maxi,x);
            mini=min(mini,x);
        }
        return gcd(maxi,mini);
    }
};
