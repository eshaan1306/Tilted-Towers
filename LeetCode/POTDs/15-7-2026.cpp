class Solution {
public:

    int gcd(int a,int b){
        if (b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    /*
    2i-1 is the ith odd number
    2i is the it even number
    2(summation of i till n) - n + 2(summation of i till n)
    */

    int gcdOfOddEvenSums(int n) {
        int summation=(n*(n+1))/2;
        int sumOdd=2*(summation)-n;
        int sumEven=2*(summation);
        return gcd(sumOdd,sumEven);
    }
};