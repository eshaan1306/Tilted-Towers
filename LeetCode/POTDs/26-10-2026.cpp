class Solution {
public:

    int di[4] = {0,1,0,-1};
    int dj[4] = {1,0,-1,0};

    bool isValid(int i,int j,int n,int m){
        if (i < 0){
            return false;
        }
        if (j < 0){
            return false;
        }
        if (i >= n){
            return false;
        }
        if (j >= m){
            return false;
        }
        return true;
    }

    long dfs(vector<vector<int>>& grid,int i,int j){
        long val = grid[i][j];
        grid[i][j] = 0;
        for(int k=0;k<4;k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if (isValid(ni,nj,grid.size(),grid[0].size())){
                if (grid[ni][nj] != 0){
                    val += dfs(grid,ni,nj);
                }
            }
        }
        return val;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] != 0){
                    long val = dfs(grid,i,j);
                    if (val%k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
