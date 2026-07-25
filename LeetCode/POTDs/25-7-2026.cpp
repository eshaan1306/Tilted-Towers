class Solution {
public:
    int maxProduct(int n) {
        int largest=INT_MIN,secondLargest=-1;
        while(n){
            int dig=n%10;
            if (dig>largest){
                secondLargest=largest;
                largest=dig;
            }
            else if (dig>secondLargest){
                secondLargest=dig;
            }
            n/=10;
        }
        return largest*secondLargest;
    }
};
