class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if (nums.size() == 1){
            return nums;
        }
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int k=2;k<nums.size();k++){
            if (arr1.back() > arr2.back()){
                arr1.push_back(nums[k]);
            }
            else{
                arr2.push_back(nums[k]);
            }
        }
        for(auto &x:arr2){
            arr1.push_back(x);
        }
        return arr1;
    }
};
