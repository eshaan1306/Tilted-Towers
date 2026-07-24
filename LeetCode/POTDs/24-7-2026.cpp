class Solution {
public:

    /*
    a xor b = c
    a xor d = c
    b xor d = 0 
    b == d
    lets say all 3 elements are the same
    then xor would be the element itself
    lets say 2 elements are the same xor would be the 3rd element
    so essentially its the same thing as 3 cases 
    so duplicates of no use only need to work for the other cases
    */

    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> unique_els;
        vector<int> seen(1501,0);
        for(auto &x:nums){
            if (!seen[x]){
                unique_els.push_back(x);
                seen[x]=1;
            }
        }
        if (unique_els.size()<=2){
            return (int)unique_els.size();
        }
        vector<int> done(2048,0);
        int ans=0;
        for(auto &x:unique_els){
            done[x]=1;
            ans++;
        }
        int n=unique_els.size();
        vector<int> pos(2048,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xr=unique_els[i]^unique_els[j];
                pos[xr]=1;
            }
        }
        for(int val=0;val<2048;val++){
            for(int i=0;i<n;i++){
                if (done[val]){
                    break;
                }
                int req=unique_els[i]^val;
                if (pos[req]){
                    done[val]=1;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
