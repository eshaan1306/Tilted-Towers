class Solution {
public:

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> coord1;
        vector<pair<int,int>> coord2;
        int n = img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (img1[i][j]){
                    coord1.push_back({i,j});
                }
                if (img2[i][j]){
                    coord2.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int> mp;
        //js try all the combinations of matching
        for(int i=0;i<coord1.size();i++){
            //we are matching ith one with jth one on the second
            for(int j=0;j<coord2.size();j++){
                int delx = coord1[i].first-coord2[j].first;
                int dely = coord1[i].second-coord2[j].second;
                mp[{delx,dely}]++;
            }
        }
        for(auto &it:mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};
