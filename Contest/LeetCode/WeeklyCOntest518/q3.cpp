class Solution {
public:

    /*
    probably stack
    if the speed of the robot on right is strictly less
    than the robot on left, they are bound to merge
    do i really need stack?
    if its equal speed, then we just check the dist
    if the speed is greater, then also distance
    */
    
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int cur = 1;
        int curSpeed = speed[n-1];
        int indx = n-1;
        for(int i=n-2;i>=0;i--){
            //bound to be one
            if (speed[i] > speed[indx]){
                //merge
                continue;
            }
            else{
                if (position[i+1] - position[i] <= distance){
                    //merge
                    continue;
                }
            }
            cur++;
            indx = i;
        }
        return cur;
    }
};©leetcode
