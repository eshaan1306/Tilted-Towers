class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        for(auto &el:arr){
            mp[el]=-1;
        }
        int rank=1;
        for(auto &it:mp){
            mp[it.first]=rank++;
        }
        vector<int> ans;
        for(auto &el:arr){
            ans.push_back(mp[el]);
        }
        return ans;
    }
};