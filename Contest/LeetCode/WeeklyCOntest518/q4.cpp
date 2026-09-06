class Solution {
public:

/*
DIJKSTRA WITH STATTESSS!!!!!
*/
    
    int minCost(vector<vector<int>>& grid, int t) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        /*
        states? 
        [i][j][dir][k]
        for dir 0 : up
        1 : down
        2 : left
        3 : right 
        4 : means nothing chosen yet
        these doesnt hold, done according to delta
        */
        vector<vector<vector<vector<int>>>> states(m,
            vector<vector<vector<int>>>(n,
                vector<vector<int>>(5,
                    vector<int>(t+1,INT_MAX)
                                )
                            )
                    );
        states[0][0][4][t] = grid[0][0];
        pq.push({grid[0][0],0,0,4,t});
        int deli[4] = {0,1,0,-1};
        int delj[4] = {1,0,-1,0};
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int curDis = cur[0];
            int i = cur[1];
            int j = cur[2];
            int curDir = cur[3];
            int leftK = cur[4];
            if (states[i][j][curDir][leftK] < curDis){
                continue;
            }
            //now we traverse everywhere
            for(int k=0;k<4;k++){
                int ni = deli[k] + i;
                int nj = delj[k] + j;
                //in the valid interval
                if (ni>=0 && nj>=0 && ni<m && nj<n){
                    //it depends upon k
                    //can go anywhere
                        if (curDir == 4){
                            int dis = curDis + grid[ni][nj];
                            if (dis < states[ni][nj][k][leftK]){
                                states[ni][nj][k][leftK] = dis;
                                pq.push({dis,ni,nj,k,leftK});
                            }
                        }
                        else{
                            if (curDir != k && leftK>0){
                                int dis = curDis + grid[ni][nj];
                                if (dis < states[ni][nj][k][leftK-1]){
                                    states[ni][nj][k][leftK-1] = dis;
                                    pq.push({dis,ni,nj,k,leftK-1});
                                }
                            }
                            else if (curDir == k){
                                int dis = curDis + grid[ni][nj];
                                if (dis < states[ni][nj][k][leftK]){
                                    states[ni][nj][k][leftK] = dis;
                                    pq.push({dis,ni,nj,k,leftK});
                                }
                            }
                }
            }
        }
        }
    int ans = INT_MAX;
    for(int d=0;d<5;d++){
        for(int i=0;i<=t;i++){
            ans = min(ans,states[m-1][n-1][d][i]);
        }
    }
        if (ans == INT_MAX){
            ans = -1;
        }
    return ans;
        }
};©leetcode
