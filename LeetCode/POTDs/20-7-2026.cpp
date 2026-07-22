class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        k%=(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int col=(j+k)%n;
                int del=(j+k)/n;
                int row=(i+del)%m;
                ans[row][col]=grid[i][j];
            }
        }
        return ans;
    }
};
