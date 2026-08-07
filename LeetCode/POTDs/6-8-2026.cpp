class Solution {
public:

    int prod(int n){
        int res=1;
        while(n){
            int dig = n%10;
            n/=10;
            res*=dig;
        }
        return res;
    }

    int smallestNumber(int n, int t) {
        for(int num=n;num<=n+10;num++){
            if ((prod(num)%t) == 0){
                return num;
            }
        }
        return -1;
    }
};
