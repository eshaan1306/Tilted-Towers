class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<long long> fib;
        fib.push_back(0);
        fib.push_back(1);
        int indx = 1;
        long long last = fib[1];
        long long secondLast = fib[0];
        while(last <= n){
            fib.push_back(last + secondLast);
            secondLast = last;
            last = fib.back();
        }
        for(int i=0;i<fib.size()-2;i++){
            if (fib[i] + fib[i+1] + fib[i+2] == n){
                return true;
            }
        }
        return false;
    }
};
