class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1;
        int org=n;
        while(n){
            int dig = (n%10);
            n/=10;
            sum += dig;
            prod*=dig;
        }
        return ((org%(sum+prod)) == 0);
    }
};
