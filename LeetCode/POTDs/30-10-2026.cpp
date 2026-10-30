class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> states(n,vector<int>(k+1,INT_MAX));
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        //{dist,consecutives,node}
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,1,0});
        states[0][1]=0;
        while(!pq.empty()){
            int dis=pq.top()[0];
            int consec=pq.top()[1];
            int node=pq.top()[2];
            pq.pop();
            char c=labels[node];
            for(auto &e:adj[node]){
                int v=e.first;
                int w=e.second;
                int newDis=dis+w;
                if (labels[v]!=c){
                    if (newDis<states[v][1]){
                        states[v][1]=newDis;
                        pq.push({newDis,1,v});
                    }
                }
                else{
                    //already at max
                    if (consec == k){
                        continue;
                    }
                    if (newDis < states[v][consec+1]){
                        states[v][consec+1] = newDis;
                        pq.push({newDis,consec+1,v});
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=k;i++){
            ans = min(ans, states[n-1][i]);
        }
        if (ans == INT_MAX){
            ans=-1;
        }
        return ans;
    }
};
