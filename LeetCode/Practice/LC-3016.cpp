class Solution {
public:

/*
9-2+1=8
*/

    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto &ch:word){
            freq[ch-'a']++;
        }
        priority_queue<pair<int,char>> pq;
        for(char ch='a';ch<='z';ch++){
            pq.push({freq[ch-'a'],ch});
        }
        int ans=0;
        int cnt=0;
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int f=cur.first;
            char ch=cur.second;
            if (f==0){
                break;
            }
            ans+=((cnt/8)+1)*f;
            cnt++;
        }
        return ans;
    }
};
