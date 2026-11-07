class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        long long n = a.size();
        long long m = b.size();
        if (n*x < y*m){
            return false;
        }
        /*
        we have made sure final string of a is greater than b
        string a would repeat at intervals of n
        string b would repeat at intervals of m 
        n*x >= b*m
        there must be some catch, we dont need to compare till the end
        n and m <=  100
        we cant compare till b*y, we need to drop it down
        we can go till n*m
        because after that we know, both will repeat
        so if n*m == 1e4, which is fine
        and if b*y is smaller than it so more chill
        */
        long long len = min(n*m,m*y);
        for(int i=0;i<n;i++){
            bool flag = true;
            if (i + m*y > n*x){
                break;
            }
            for(int j=0;j<len;j++){
                int ix1 = (i+j)%n;
                int ix2 = j%m;
                if (a[ix1] != b[ix2]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                return true;
            }
        }
        return false;
    }
};
