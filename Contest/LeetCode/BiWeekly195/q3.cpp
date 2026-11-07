class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        /*
    wait, im supposed to track the index of ab
        */
        int ab = -1;
        int a = - 1;
        long long ans = 0;
        int l = 0 , r= 0;
        while(r < n){
            if (s[r] == 'a'){
                a = r;
            }
            else if (s[r] == 'b'){
                if (a >= l){
                    ab = a;
                }
            }
            else{
                //we have subsequence so we need to shift it to the right of current ab, actually we need to shift not right, but at ab
                //okay so we need minimum shift, that would be the index of a at this ab
                if (ab >= l){
                    l = ab + 1;
                }
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};
