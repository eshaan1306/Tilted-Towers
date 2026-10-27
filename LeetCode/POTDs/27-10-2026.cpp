class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m-1;i++){
            string col(n,'#');
            col[0]='.';
            ans.push_back(col);
        }
        string temp(n,'.');
        ans.push_back(temp);
        return ans;
    }
};
