class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        vector<int> del(2);
        del[0]=abs(start[0]-target[0]);
        del[1]=abs(start[1]-target[1]);
        int xr=0;
        for(int i=0;i<2;i++){
            xr^=(del[i]&1);
        }
        return xr==0;
    }
};
