class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndx=-1;
        int minVal=INT_MAX;
        int maxIndx=-1;
        int maxVal=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if (nums[i] > maxVal){
                maxVal = nums[i];
                maxIndx = i;
            }
            if (nums[i] < minVal){
                minVal = nums[i];
                minIndx = i;
            }
        }
        int left = min(minIndx,maxIndx);
        int right = max(minIndx,maxIndx);
        int jump = right-left;
        left++;
        right = n-right;
        int op1 = (left+right);
        int op2 = left+jump;
        int op3 = right+jump;
        return min(op1,min(op2,op3));
    }
};
