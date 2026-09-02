class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = true;
        bool even = true;
        for(int i=0;i<nums1.size();i++){
            bool curOdd = (nums1[i]&1);
            bool curEven = !(nums1[i]&1);
            for(int j=0;j<nums1.size();j++){
                if (j==i){
                    continue;
                }
                int val = abs(nums1[i]-nums1[j]);
                curOdd |= (val&1);
                curEven |= !(val&1);
            }
            odd &= curOdd;
            even &= curEven;
        }
        return (odd || even);
    }
};
