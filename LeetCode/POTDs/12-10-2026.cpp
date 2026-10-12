class Solution {
public:

/*
let the nums be x and y
and == less than min(x,y)
or == more than max(x,y)
lets ssay we have 
1000 and 0111
it becomes 1111
and 0000 
so lets say there is a disagreement on some bit i 
all that is happening is the bits are switching, nothing else
if number x > y, we would want to OR on x, the bits that would go to x
and would have a greater increase on the sum on the square
thats because (x+100)^2 - x^2 == const + 200x
increase depends on x
*/

    long long const MOD = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        vector<int> bits(32,0);
        for(int b=0;b<32;b++){
            for(int i=0;i<n;i++){
                long long cur = 1LL*nums[i];
                if (cur & (1LL<<b)){
                    bits[b]++;
                }
            }
        }
        for(int i=0;i<k;i++){
            long long cur = 0;
            for(int b=0;b<32;b++){
                if (bits[b]){
                    cur |= (1LL<<b);
                    bits[b]--;
                }
            }
            cur = (cur*cur)%MOD;
            ans = (ans+cur)%MOD;
        }
        return (int)ans;
    }
};
