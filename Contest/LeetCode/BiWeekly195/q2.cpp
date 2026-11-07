class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();
        int m = groupSize.size();
        int i = 0;
        vector<vector<int>> states;
        for(int i=0;i<n;i++){
            int type = types[i];
            int col = colors[i];
            if (states.size() > 0 && states.back()[0] == type && states.back()[1] == col){
                int indx = states.size()-1;
                states[indx][2]++;
                if (states[indx][2] == groupSize[type]){
                    states.pop_back();
                }
            }
            else{
                vector<int> state = {type,col,1};
                if (groupSize[type] > 1){
                    states.push_back(state);
                }
            }
        }
        return states.size() == 0;
    }
};
