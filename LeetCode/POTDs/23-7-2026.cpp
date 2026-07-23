class Solution {
public:

    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if (n<=2){
            return n;
        }
        int dig=0;
        while(n){
            dig++;
            n=(n>>1);
        }
        return (1<<dig);
    }
};
