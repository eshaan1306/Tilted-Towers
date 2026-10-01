class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        map<int,int> freq;
        for(auto &x:nums){
            freq[x]++;
            if (freq[x] == 1){
                pq.push(x);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            vector<int> temp;
            while(!pq.empty()){
                int cur = pq.top();
                pq.pop();
                ans.push_back(cur);
                freq[cur]--;
                if (freq[cur] > 0){
                    temp.push_back(cur);
                }
            }
            for(auto &x:temp){
                pq.push(x);
            }
        }
        return ans;
    }
};
