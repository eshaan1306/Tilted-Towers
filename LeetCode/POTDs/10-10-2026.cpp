class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL*(k1 + k2);
        vector<long long> diff(n);
        for (int i=0;i<n;i++){
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        sort(diff.rbegin(),diff.rend());
        diff.push_back(0);
        for (int i=0;i<n;i++){
            //num of els to change
            long long cnt = i+1;
            //cur value of those elements
            long long cur = diff[i];
            //val to achieve
            long long target = diff[i+1];
            long long cost = (cur - target)*cnt;
            if (k>=cost){
                k -= cost;
            }
            else{
                /*
                this means we have cnt number of cur values
                we cant make all of them target 
                so out optimal should be to decrease each of them
                by 1, one by one
                */
                //value by EACH of them decreases
                long long del = k/cnt;
                //number of curs, which would decrease by 1
                long long extra = k%cnt;
                cur -= del;
                long long cntA = extra;
                long long cntB = cnt - extra;
                long long ans = ((cur-1)*(cur-1)*cntA) + (cur*cur*cntB);
                //rem values
                for(int j=i+1;j<n;j++){
                    ans += diff[j]*diff[j];
                }
                return ans;
            }
        }
        return 0;
    }
};
