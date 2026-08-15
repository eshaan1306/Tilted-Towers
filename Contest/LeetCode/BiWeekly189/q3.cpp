class Solution {
public:

    /*
we start with 9 1 digit
then 10 2 digit for 9 times 
then 10 3 digit for (10 -> 99) 90 times
then 10 4 digits for (100 -> 999) 900 times
hmmm there is clearly some patter
    */
    
    int kthDigit(long long k) {
        if (k<=9){
            return k;
        }
        long long numDig=1;
        long long cnt=9;
        long long numBlocks=1;
        //tc? okay so yeah numBlocks increases by x10 so we good
        while(true){
            long long present = 1LL*numDig*cnt*numBlocks;
            //in this range 
            if (k<=present){
                break;
            }
            else{
                k-=present;
                if (numDig==1){
                    numDig++;
                    cnt++;
                    numBlocks=9;
                }
                else{
                    numDig++;
                    numBlocks*=10;
                }
            }
        }
        //now we just find which nth number in the range 
        long long n = (k+numDig-1)/(numDig);
        long long temp1 = 1;
        for(int i=0;i<numDig-1;i++){
            temp1*=10;
        }
        string s(numDig,'9');
        long long temp2 = stoll(s);
        //ok so now also for increasing decreasing we need b
        /*
        well
        */
        long long numFromEnd = temp2 - n +1;
        long long numFromStart = temp1 + n -1;
        long long del = numFromStart - temp1;
        long long b = temp1/10;
        long long extra = (del/10);
        b+=extra;
        //i think we are the range
        long long pos = del%10;
        long long num;
        if (b&1){
            num = b*10 + 9 - pos;
            
        }
        else{
            num = b*10 + pos;
        }
        string t = to_string(num);
        //indx?
        int indx = (k-1)%numDig;
        return t[indx] - '0';
    }
};
