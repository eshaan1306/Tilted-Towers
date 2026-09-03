class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int minOdd =INT_MAX,minEven=INT_MAX;
        for(auto &x:nums1){
            if (x&1){
                minOdd=min(minOdd,x);
            }
            else{
                minEven=min(minEven,x);
            }
        }
        //check for odd
        bool flag=true;
        for(int i=0;i<n;i++){
            if (!(nums1[i]&1)){
                //its even
                //so subtract with odd
                if (minOdd == INT_MAX){
                    flag=false;
                    break;
                }
                int val = nums1[i]-minOdd;
                if (val<1){
                    flag=false;
                    break;
                }
            }
        }
        if (flag){
            return true;
        }
        //check for even
        flag=true;
        for(int i=0;i<n;i++){
            if ((nums1[i]&1)){
                //its odd
                //so subtract with odd
                if (minOdd == INT_MAX){
                    flag=false;
                    break;
                }
                int val = nums1[i]-minOdd;
                if (val<1){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
};
