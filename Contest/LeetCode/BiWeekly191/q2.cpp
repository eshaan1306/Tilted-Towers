class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<pair<int,int>> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0;
        int ans=0;
        while(i<n){
            int num = v[i].first;
            vector<int> indices;
            int f=0;
            while(i<n && v[i].first == num){
                f++;
                indices.push_back(v[i].second);
                i++;
            }
            if (f<3){
                continue;
            }
            int gap = indices[1]-indices[0];
            bool flag = true;
            for(int j=2;j<indices.size();j++){
                if (indices[j] - indices[j-1] != gap){
                    flag = false;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
};
