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

    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if (isValid(ni,nj,grid.size(),grid[0].size())){
                if (grid[ni][nj] == 0 && !vis[ni][nj]){
                    dfs(grid,ni,nj,vis);
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == 0 && !vis[i][j]){
                    ans++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j] = 0;
            }
        }
        for(int j=0;j<m;j++){
            if (grid[0][j] == 0 && !vis[0][j]){
                ans--;
                dfs(grid,0,j,vis);
            }
        }
        for(int j=0;j<m;j++){
            if (grid[n-1][j] == 0 && !vis[n-1][j]){
                ans--;
                dfs(grid,n-1,j,vis);
            }
        }
        for(int i=0;i<n;i++){
            if (grid[i][0] == 0 && !vis[i][0]){
                ans--;
                dfs(grid,i,0,vis);
            }
        }
        for(int i=0;i<n;i++){
            if (grid[i][m-1] == 0 && !vis[i][m-1]){
                ans--;
                dfs(grid,i,m-1,vis);
            }
        }
        return ans;
    }
};
