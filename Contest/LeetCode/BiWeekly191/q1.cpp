class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans=0;
        for(int num=0;num<=100;num++){
            int freq=0;
            vector<int> pos;
            for(int i=0;i<nums.size();i++){
                if (nums[i] == num){
                    pos.push_back(i);
                    freq++;
                }
            }
            if (freq==3){
                if (pos[1]-pos[0] == pos[2]-pos[1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
