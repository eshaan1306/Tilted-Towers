class Solution {
public:

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        int i=0;
        vector<int> ans(n);
        while(i<n){
            vector<int> vals,indices;
            vals.push_back(temp[i].first);
            indices.push_back(temp[i].second);
            int j = i+1;
            while(j<n && ((temp[j].first - temp[j-1].first) <= limit)){
                vals.push_back(temp[j].first);
                indices.push_back(temp[j].second);
                j++;
            }
            //val must be already sorted
            sort(indices.begin(),indices.end());
            for(int k=0;k<vals.size();k++){
                ans[indices[k]] = vals[k];
            }
            i=j;
        }
        return ans;
    }
};
