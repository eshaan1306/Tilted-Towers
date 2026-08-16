class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
    vector<int> cnt(3);
    for (auto &x:stones){
        cnt[x%3]++;
    }
    if (cnt[0]&1) {
        return abs(cnt[1] - cnt[2]) > 2;
    }
    return (cnt[1]>0) && (cnt[2]>0);
}
};
