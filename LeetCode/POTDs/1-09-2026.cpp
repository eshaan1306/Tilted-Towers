class Solution {
public:

    /*
    bfs
    state = {i,j,mask,energy}
    mask tells which litter we have picked
    for same {i,j,mask},
    if we have already reached with more energy,
    no point coming again with lesser energy
    */

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sx,sy;
        int cnt = 0;
        vector<vector<int>> id(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (classroom[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L'){
                    id[i][j] = cnt++;
                }
            }
        }
        int fullMask = (1<<cnt)-1;
        // {x,y,mask,current energy}
        queue<tuple<int,int,int,int>> q;
        // maximum energy with which we have reached {i,j,mask}
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1<<cnt,-1)
            )
        );
        q.push({sx,sy,0,energy});
        best[sx][sy][0] = energy;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int moves = 0;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [x,y,mask,cur] = q.front();
                q.pop();
                if (mask == fullMask){
                    return moves;
                }
                if (cur == 0){
                    continue;
                }
                for(int k=0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n){
                        continue;
                    }
                    if (classroom[nx][ny] == 'X'){
                        continue;
                    }
                    int newEnergy = cur-1;
                    int newMask = mask;
                    if (classroom[nx][ny] == 'R'){
                        newEnergy = energy;
                    }
                    if (classroom[nx][ny] == 'L'){
                        newMask |= (1<<id[nx][ny]);
                    }
                    if (best[nx][ny][newMask] >= newEnergy){
                        continue;
                    }
                    best[nx][ny][newMask] = newEnergy;
                    q.push({nx,ny,newMask,newEnergy});
                }
            }
            moves++;
        }
        return -1;
    }
};
