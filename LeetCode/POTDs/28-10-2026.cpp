class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //states : i,j,xor, to check if its possible to reach i,j with k xor
        vector<vector<vector<int>>> states(m,
            vector<vector<int>>(n,
                vector<int>(2048,0)
            )
        );
        states[0][0][grid[0][0]] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<2048;k++){
                    //basically the start
                    if (i==0 && j==0){
                        continue;
                    }
                    int req = k^grid[i][j];
                    //see if we can come from left
                    if (i > 0){
                        states[i][j][k] |= states[i-1][j][req];
                    }
                    if (j > 0){
                        states[i][j][k] |= states[i][j-1][req];
                    }
                }
            }
        }
        int ans = 2048;
        for(int cand=0;cand<2048;cand++){
            if (states[m-1][n-1][cand]){
                ans = cand;
                break;
            }
        }
        return ans;
    }
};
