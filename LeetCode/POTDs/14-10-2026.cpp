class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans(num,'0');
        if (9*num < sum){
            return "";
        }
        for(int i=0;i<num;i++){
            if (sum == 0){
                break;
            }
            int dig = min(9,sum);
            ans[i] = dig + '0';
            sum-=dig;
        }
        return ans;
    }
};
