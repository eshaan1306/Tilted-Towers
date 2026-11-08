class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] == 1){
                    bool flag = false;
                    for(int k=0;k<m;k++){
                        if (k == i){
                            continue;
                        }
                        if (grid[k][j] == 1){
                            flag = true;
                            break;
                        }
                    }
                    if (!flag){
                        for(int k=0;k<n;k++){
                            if (k == j){
                                continue;
                            }
                            if (grid[i][k] == 1){
                                flag = true;
                                break;
                            }
                        }
                    }
                    ans += flag;
                }
            }
        }
        return ans;
    }
};
