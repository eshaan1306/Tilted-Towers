class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        //{start,end}
        vector<pair<int,int>> intervals;
        int i=0;
        int n=s.size();
        while(i<n){
            if (s[i]=='1'){
                i++;
                continue;
            }
            int startIndx=i,endIndx=i;
            while(i<n && s[i]=='0'){
                endIndx=i;
                i++;
            }
            intervals.push_back({startIndx,endIndx});
        }
        int ans=0;
        for(auto &ch:s){
            if (ch=='1'){
                ans++;
            }
        }
        int extra=0;
        for(int i=1;i<intervals.size();i++){
            int left=intervals[i-1].second-intervals[i-1].first+1;
            int right=intervals[i].second-intervals[i].first+1;
            extra=max(extra,left+right);
        }
        return ans+extra;
    }
};
