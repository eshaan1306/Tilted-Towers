class Solution {
public:

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        long long time = 0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> busyServers;
        set<int> isFree;
        for(int i=0;i<k;i++){
            isFree.insert(i);
        }
        vector<int> cnt(k,0);
        for(int i=0;i<n;i++){
            time = max(time,1LL*arrival[i]);
            while(!busyServers.empty()){
                auto cur = busyServers.top();
                if (cur.first <= time){
                    busyServers.pop();
                    isFree.insert(cur.second);
                }
                else{
                    break;
                }
            }
            //drop the fkn query
            if (isFree.size() == 0){
                continue;
            }
            auto it = isFree.lower_bound(i%k);
            if (it == isFree.end()){
                it = isFree.begin();
            }
            int server = *it;
            isFree.erase(server);
            busyServers.push({time + load[i],server});
            cnt[server]++;
        }
        int maxi = 0;
        for(auto &x:cnt){
            maxi = max(maxi,x);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            if (cnt[i] == maxi){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
