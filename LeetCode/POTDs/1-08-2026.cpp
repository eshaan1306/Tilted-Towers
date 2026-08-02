class Solution {
public:

    bool soln(int i,int j,vector<int> &nums,int p1,int p2,int chance){
        if (i>j){
            if (p1>=p2){
                return true;
            }
            return false;
        }
        if (chance){
            p1+=nums[i];
            if (soln(i+1,j,nums,p1,p2,!chance)){
                return true;
            }
            p1-=nums[i];
            p1+=nums[j];
            if (soln(i,j-1,nums,p1,p2,!chance)){
                return true;
            }
            p1-=nums[j];
            return false;
        }
        else{
            p2+=nums[i];
            if (!soln(i+1,j,nums,p1,p2,!chance)){
                return false;
            }
            p2-=nums[i];
            p2+=nums[j];
            if (!soln(i,j-1,nums,p1,p2,!chance)){
                return false;
            }
            p2-=nums[j];
            return true;
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return soln(0,nums.size()-1,nums,0,0,1);
    }
};
