class Solution {
public:

/*
2-9 digits 
for 9 digits-1
for 8 digits-2
for 7 digits-3
....
for 2 digits-8
1+2+3..+8 = 36
*/
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;
        for(int dig=2;dig<=9;dig++){
            for(int start=1;start<=9-dig+1;start++){
                string num;
                num.push_back(start+'0');
                for(int i=1;i<dig;i++){
                    num.push_back(start+i+'0');
                }
                int el=stoi(num);
                nums.push_back(el);
            }
        }
        vector<int> ans;
        for(auto &cand:nums){
            if (cand>high){
                break;
            }
            if (cand<low){
                continue;
            }
            ans.push_back(cand);
        }
        return ans;
    }
};