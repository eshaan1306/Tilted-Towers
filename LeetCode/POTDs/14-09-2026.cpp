class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //first rec is on the right 
        if (rec1[0] >= rec2[2]){
            return false;
        }
        //first rec is on the left
        if (rec1[2] <= rec2[0]){
            return false;
        }
        //first rec is above
        if (rec1[1] >= rec2[3]){
            return false;
        }
        //first rec is below
        if (rec1[3] <= rec2[1]){
            return false;
        }
        return true;
    }
};
