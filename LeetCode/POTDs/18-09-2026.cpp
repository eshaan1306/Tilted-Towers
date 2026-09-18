class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        //to form intervals
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        int n = s.size();
        for(int i=0;i<n;i++){
            if (first[s[i]-'a'] == -1){
                first[s[i]-'a'] = i;
            }
            last[s[i]-'a'] = i;
        }
        /*
        for every character, create the minimum valid interval
        starting from its first occurrence
        */
        vector<vector<int>> intervals;
        for(int i=0;i<26;i++){
            if (first[i] == -1){
                continue;
            }
            int l = first[i];
            int r = last[i];
            bool possible = true;
            for(int j=l;j<=r;j++){
                int c = s[j]-'a';
                //this character occurs before our starting point
                //so this substring can never contain all its occurrences
                if (first[c] < l){
                    possible = false;
                    break;
                }
                //if this character occurs later, substring must expand
                r = max(r,last[c]);
            }
            if (possible){
                intervals.push_back({l,r});
            }
        }
        /*
        now we have all minimum valid intervals
        we want maximum number of non-overlapping intervals.
        standard greedy -> sort by ending time.
        since every interval we generated is already minimum,
        this also gives minimum total length
        */
        sort(intervals.begin(),intervals.end(),
        [](vector<int> &a,vector<int> &b){
            return a[1] < b[1];
        });
        vector<string> ans;
        int prevEnd = -1;
        for(auto &interval:intervals){
            int l = interval[0];
            int r = interval[1];
            if (l > prevEnd){
                ans.push_back(s.substr(l,r-l+1));
                prevEnd = r;
            }
        }
        return ans;
    }
};
