class Solution {
public:

    /*
    so atleast one bit must appear odd number of times
    we can first calculate count of the each bit, if atleast one of them
    is odd number of times then answer would be n 
    now what if all of them are even?
    then i think removing only a single element is enough because lets say we have 
    2a , 2b , 2c , .... 2z for each bit 
    removing a single element would make for atleast 1 bit i as 
    2i - 1, which would make that particular bit odd 
    we can handle the zeroes separately because they might cause probs
    */

    int longestSubsequence(vector<int>& nums) {
        vector<int> cntBit(32,0);
        int n = nums.size();
        int cntZero=0;
        for(int i=0;i<n;i++){
            if (nums[i] == 0){
                cntZero++;
                continue;
            }
            for(int bit=0;bit<32;bit++){
                if ((nums[i]>>bit) & 1){
                    cntBit[bit]++;
                }
            }
        }
        for(int bit=0;bit<32;bit++){
            if (cntBit[bit] & 1){
                return n;
            }
        }
        if (cntZero == n){
            return 0;
        }
        return n-1;
    }
};
