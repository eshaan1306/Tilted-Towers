class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), comp);
        int m = queries.size();
        vector<pair<int,int>> q;
        for(int i=0;i<m;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        vector<int> freq(n+1,0), arr(m);
        int l = 0, r = 0, cnt = 0;
        int sz = logs.size();
        for(auto &entry:q){
            int t = entry.first;
            int indx = entry.second;
            while(r < sz && logs[r][1] <= t){
                int s = logs[r][0];
                if (freq[s] == 0){
                    cnt++;
                }
                freq[s]++;
                r++;
            }
            while(l < r && logs[l][1] < t-x){
                int s = logs[l][0];
                freq[s]--;
                if (freq[s] == 0){
                    cnt--;
                }
                l++;
            }
            arr[indx] = n - cnt;
        }
        return arr;
    }
};
