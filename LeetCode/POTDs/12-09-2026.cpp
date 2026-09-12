class Solution {
public:

    static bool comp(vector<int> &a,vector<int> &b){
        return a[0] < b[0];
    }

    vector<vector<pair<long long,vector<int>>>> dp;
    vector<vector<int>> vis;

    pair<long long,vector<int>> soln(vector<vector<int>>& intervals,int i,int cnt){
        if (i==intervals.size() || cnt==4){
            return {0,{}};
        }
        if(vis[i][cnt]){
            return dp[i][cnt];
        }
        vis[i][cnt]=1;
        //skip this
        auto op1 = soln(intervals,i+1,cnt);
        //pick this
        int indx = intervals.size();
        int low=i+1;
        int high=intervals.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(intervals[mid][0] > intervals[i][1]){
                indx=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        auto op2 = soln(intervals,indx,cnt+1);
        op2.first += intervals[i][2];
        op2.second.push_back(intervals[i][3]);
        sort(op2.second.begin(),op2.second.end());
        pair<long long,vector<int>> ans;
        if(op1.first > op2.first){
            ans=op1;
        }
        else if(op2.first > op1.first){
            ans=op2;
        }
        else{
            if(op1.second < op2.second){
                ans=op1;
            }
            else{
                ans=op2;
            }
        }
        return dp[i][cnt]=ans;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        for(int i=0;i<intervals.size();i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        dp.resize(n,vector<pair<long long,vector<int>>>(4));
        vis.resize(n,vector<int>(4,0));
        return soln(intervals,0,0).second;
    }
};
