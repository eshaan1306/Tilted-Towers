class Solution {
public:
    /*
    1 : {2,3,4,5}
    2 : {4,5,6,7}
    3 : {6,7,8,9}
    if 2 and 3 they take away 1
    if 4 and 5 they take away 1,2
    if 6 and 7 they take away 2,3
    if 8 and 9 they take away 3
    */
    vector<int> helper(int pos){
        if (pos == 2 || pos == 3){
            return {1};
        }
        else if (pos == 4 || pos == 5){
            return {1,2};
        }
        else if (pos == 6 || pos == 7){
            return {2,3};
        }
        else if (pos == 8 || pos == 9){
            return {3};
        }
        return {};
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<int> rows;
        map<int,vector<int>> mp;
        for(auto &seat:reservedSeats){
            int row = seat[0];
            int pos = seat[1];
            rows.insert(row);
            mp[row].push_back(pos);
        }
        int ans = (n-(rows.size()))*2;
        for(auto &it:mp){
            set<int> blocks;
            for(auto &pos:it.second){
                for(auto &block:helper(pos)){
                    blocks.insert(block);
                }
            }
            if (blocks.empty()){
                ans += 2;
            }
            else if (blocks.size() == 1 && blocks.count(2)){
                ans += 2;
            }
            else if (blocks.size() < 3){
                ans += 1;
            }
        }
        return ans;
    }
};
