class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers, busyServers;
        for (int i=0;i<n;i++){
            freeServers.push({servers[i],i});
        }
        vector<int> ans(m);
        long long time = 0;
        for (int j=0;j<m;j++){
            time = max(time, (long long)j);
            while (!busyServers.empty() && busyServers.top().first <= time){
                int idx = busyServers.top().second;
                busyServers.pop();
                freeServers.push({servers[idx], idx});
            }
            if (freeServers.empty()) {
                time = max(time, 1LL*busyServers.top().first);
                while (!busyServers.empty() && busyServers.top().first <= time) {
                    int idx = busyServers.top().second;
                    busyServers.pop();
                    freeServers.push({servers[idx], idx});
                }
            }
            int serverIndex = freeServers.top().second;
            freeServers.pop();
            ans[j] = serverIndex;
            busyServers.push({time + tasks[j], serverIndex});
        }
        return ans;
    }
};
