class Solution {
public:

    vector<vector<vector<int>>> dp;

    bool soln(vector<vector<char>> &grid,int i,int j,int cnt){
        if (i >= grid.size() || j>= grid[0].size()){
            return false;
        }
        if (grid[i][j] == '('){
            cnt++;
        }
        else{
            if (cnt == 0){
                return false;
            }
            cnt--;
        }
        if (i == grid.size()-1 && j == grid[0].size()-1){
            return cnt == 0;
        }
        if (dp[i][j][cnt] != -1){
            return dp[i][j][cnt];
        }
        bool op1 = soln(grid,i+1,j,cnt);
        if (op1){
            return dp[i][j][cnt] = true;
        }
        bool op2 = soln(grid,i,j+1,cnt);
        if (op2){
            return dp[i][j][cnt] = true;
        }
        return dp[i][j][cnt] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m+n-1)&1){
            return false;
        }
        dp.resize(m,
            vector<vector<int>>(
                n,vector<int>(m+n,-1)
            ));
        return soln(grid,0,0,0);
    }
};
