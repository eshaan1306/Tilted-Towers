class Solution {
public:

    vector<int> findMissingElements(vector<int>& nums) {
        int smallest=INT_MAX,largest=INT_MIN;
        vector<int> present(101,0);
        for(auto &x:nums){
            smallest=min(smallest,x);
            largest=max(largest,x);
            present[x]=1;
        }
        vector<int> ans;
        for(int i=smallest+1;i<largest;i++){
            if (!present[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
