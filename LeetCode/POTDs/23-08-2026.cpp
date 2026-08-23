class Solution {
public:

/*
left + placedLeft = right + placedRight
placedLeft - placedRight = right - left
if total '?' is odd
Alice gets one extra move so he always wins.
if total '?' is even
Bob can counter Alice's moves.
*/

    bool sumGame(string num) {
        int left=0,right=0;
        int n = num.size();
        int cntLeft=0,cntRight=0;
        for(int i=0;i<n/2;i++){
            if (num[i] == '?'){
                cntLeft++;
                continue;
            }
            left += num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if (num[i] == '?'){
                cntRight++;
                continue;
            }
            right += num[i]-'0';
        }
        if ((cntLeft + cntRight)&1){
            return true;
        }
        return 2*(right-left) != 9*(cntLeft-cntRight);
    }
};
