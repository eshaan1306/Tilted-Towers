class Solution {
public:

/*
missed the overlapping part
so basically we would take the shortest
possible we can, no need to expand
we can just form the intervals,then 
the problem basically breaks down to max 
non overlapping intervals
*/

vector<vector<int>> intervals;

    bool static comp(vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    }

    void helper(int i,int j,string &s,int k){
        while(i>=0 && j<s.size()){
            if (s[i] == s[j]){
                if (j-i+1 >= k){
                    intervals.push_back({i,j});
                    break;
                }
                else{
                    i--,j++;
                }
            }
            else{
                break;
            }
        }
    }

    int maxPalindromes(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i++){
            //odd
            helper(i,i,s,k);
            //even
            helper(i-1,i,s,k);
        }
        sort(intervals.begin(),intervals.end(),comp);
        int r = INT_MIN;
        int ans = 0;
        for(auto &interval:intervals){
            if (interval[0] > r){
                ans++;
                r = interval[1];
            }
        }
        return ans;
   }
};
